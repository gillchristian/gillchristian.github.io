import 'whatwg-fetch'

import 'enhacers/header'

import {loadMarkdown} from 'lib/markdown'

loadMarkdown(
  'musts-content',
  'https://raw.githubusercontent.com/gillchristian/raws/master/musts.md'
)

loadMarkdown(
  'dev-resources',
  'https://raw.githubusercontent.com/gillchristian/dev-resources/master/README.md'
)
