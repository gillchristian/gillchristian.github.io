var header = document.querySelector("header")
var headerFix = document.querySelector(".header-fix")

if (headerFix) {
  headerFix.style.height = header.offsetHeight + 'px'

  var headroom  = new Headroom(header)
  headroom.init();
}
