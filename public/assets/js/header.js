var header = document.querySelector("header")
var headerFix = document.querySelector(".header-fix")

if (headerFix && header) {
  headerFix.style.height = header.offsetHeight + 'px'
  
  var config = {
    offset : 100,
    tolerance : {
      up : 15,
      down : 15
    },
  }

  var headroom  = new Headroom(header, config)
  headroom.init();
}
