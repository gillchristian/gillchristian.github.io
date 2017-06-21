import 'whatwg-fetch'
import {initHighlightingOnLoad} from 'highlight.js'

import 'enhacers/header'

import {loadMarkdown} from 'lib/markdown'

loadMarkdown(
  'reading-content',
  'https://raw.githubusercontent.com/gillchristian/raws/master/reading-list.md'
)

loadMarkdown(
  'musts-content',
  'https://raw.githubusercontent.com/gillchristian/raws/master/musts.md'
)

loadMarkdown(
  'dev-resources',
  'https://raw.githubusercontent.com/gillchristian/dev-resources/master/README.md'
)

// highlight code blocks
initHighlightingOnLoad()
