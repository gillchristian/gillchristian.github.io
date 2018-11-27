const express = require('express')
const bodyParser = require('body-parser')
const cors = require('cors')
const helmet = require('helmet')
const morgan = require('morgan')
const chalk = require('chalk')
const trae = require('trae')
const R = require('ramda')
const { format } = require('date-fns')

const app = express()

// -------------------------------------

app.use(cors())
app.use(helmet())
app.use(bodyParser.urlencoded({ extended: true }))
app.use(bodyParser.json())
app.use(morgan('tiny'))

// -------------------------------------

const parseJSON = t => JSON.parse(t)

const formatDate = date => format(new Date(date), 'YYYY-MM-DD')

const getEntries = data =>
  Object.values(data.payload.references.Post).map(value => {
    const collectionDomain = R.path(
      [
        'payload',
        'references',
        'Collection',
        R.prop('homeCollectionId', value),
        'domain',
      ],
      data
    )

    const domain = value.homeCollectionId
      ? `http://${collectionDomain}`
      : 'http://medium.com/@gillchristiang'

    return {
      title: R.prop('title', value),
      subtitle: R.path(['content', 'subtitle'], value),
      tags: R.pathOr([], ['virtuals', 'tags'], value).map(t => t.slug),
      publishedAt: formatDate(R.prop('firstPublishedAt', value)),
      url: `${domain}/${value.uniqueSlug}`,
    }
  })

const GETENTRIES = R.compose(
  getEntries,
  parseJSON,
  R.replace(/^.*\>/, ''),
  R.prop('data')
)

app.use('/', (req, res, next) => {
  trae
    .get('https://medium.com/@gillchristiang?format=json', { bodyType: 'text' })
    .then(GETENTRIES)
    .then(entries => {
      res.status(200).json({ entries })
    })
    .catch(error => {
      // TODO: add more errors
      res.status(500).json({ error })
    })
})

// -------------------------------------

const config = {
  port: process.env.PORT || 3000,
}

app.listen(config.port, () => {
  console.log()
  console.log(chalk`Listening on {cyan http://localhost:${config.port}}`)
  console.log()
})
