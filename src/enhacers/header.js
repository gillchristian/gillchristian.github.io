import Headroom from 'headroom.js'

const header = document.querySelector('header')
const headerFix = document.querySelector('.header-fix')

if (headerFix && header) {
  const headroom = new Headroom(header, {
    offset: 100,
    tolerance: {
      up: 15,
      down: 15
    }
  })
  headroom.init()
}
