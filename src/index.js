import 'whatwg-fetch'
import { initHighlightingOnLoad } from 'highlight.js'

import 'enhacers/header'

import { loadMarkdown } from 'lib/markdown'
import { readOrReject } from 'lib/fetch'

import data from '../public/_data.json'

import { githubFeed } from './gh-events'

initHighlightingOnLoad()

// --- load content ------------------------------------------------------------

loadMarkdown(
  'reading-content',
  'https://raw.githubusercontent.com/gillchristian/goals/master/content-list/books.md',
  md => {
    const [, ...tail] = md.split('\n')
    return tail.join('\n')
  },
)

loadMarkdown(
  'musts-content',
  'https://raw.githubusercontent.com/gillchristian/raws/master/musts.md',
)

loadMarkdown(
  'dev-resources',
  'https://raw.githubusercontent.com/gillchristian/dev-resources/master/README.md',
)

// -----------------------------------------------------------------------------

async function renderFeed() {
  const feed = document.getElementById('github-feed')

  if (!feed) {
    return
  }

  try {
    const markup = await githubFeed()
    feed.innerHTML = markup
  } catch (e) {
    console.log(e)
  }
}

renderFeed()

// --- home background switcher ------------------------------------------------

const getRandomIndex = xs => Math.floor(Math.random() * Math.floor(xs.length))

const homeBg = document.querySelector('body.home')
const reloadIcon = document.querySelector('.reload-bg')

if (homeBg && reloadIcon) {
  reloadIcon.addEventListener('click', () => {
    const image = data.backgrounds[getRandomIndex(data.backgrounds)]

    homeBg.style.backgroundImage = `url(${image})`
  })
}

// -----------------------------------------------------------------------------

const corsUrl = 'https://cors-anywhere.herokuapp.com/'
const corseable = url => `${corsUrl}${encodeURI(url)}`

// show articles

async function loadPosts() {
  const target = document.getElementById('blog-posts')
  if (!target) {
    return
  }
  const url = corseable('https://medium.com/@gillchristiang/latest?format=json')
  try {
    const response = await fetch(url, {
      headers: {
        'Access-Control-Allow-Origin': '*',
        origin: 'https://gillchristiang.xyz',
        'X-Requested-With': 'https://gillchristiang.xyz',
      },
    })
    const json = await readOrReject(response, false)

    console.log(json.payload.references.Post)
  } catch (err) {
    console.error(err)
  }
}

loadPosts()
