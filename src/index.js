import 'whatwg-fetch'
import { initHighlightingOnLoad } from 'highlight.js'

import 'enhacers/header'

import { loadMarkdown } from 'lib/markdown'

loadMarkdown(
  'reading-content',
  'https://raw.githubusercontent.com/gillchristian/goals/master/content-list/books.md',
  md => {
    const [head, ...tail] = md.split('\n')
    return tail.join('\n')
  }
)

loadMarkdown(
  'musts-content',
  'https://raw.githubusercontent.com/gillchristian/raws/master/musts.md'
)

loadMarkdown(
  'dev-resources',
  'https://raw.githubusercontent.com/gillchristian/dev-resources/master/README.md'
)

loadMarkdown(
  'goals',
  'https://raw.githubusercontent.com/gillchristian/goals/master/README.md',
  md => {
    const [head, ...tail] = md.split('\n')
    const comments = '_Find the repo [here](https://github.com/gillchristian/goals)_.\n'

    return [head, comments, ...tail].join('\n')
  }

)

// highlight code blocks
initHighlightingOnLoad()
