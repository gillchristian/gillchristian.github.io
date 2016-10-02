import 'whatwg-fetch'

import 'enhacers/header'

import {loadMarkdown} from 'lib/markdown'

loadMarkdown(
  'musts-content',
  'https://raw.githubusercontent.com/gillchristian/raws/master/musts.md'
)
