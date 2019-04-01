import 'whatwg-fetch'
import { initHighlightingOnLoad } from 'highlight.js'

import 'enhacers/header'
import { fetchDevToArticles } from 'enhacers/articles'

import { loadMarkdown } from 'lib/markdown'
import { readOrReject } from 'lib/fetch'

import data from '../public/_data.json'

initHighlightingOnLoad()

// --- load content ------------------------------------------------------------

fetchDevToArticles('articles')

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
