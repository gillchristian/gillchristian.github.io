'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});

var _react = require('/home/altoros/Documents/dev/gillchristian.github.io/node_modules/react/react.js');

var _react2 = _interopRequireDefault(_react);

var _link = require('/home/altoros/Documents/dev/gillchristian.github.io/node_modules/next/dist/lib/link.js');

var _link2 = _interopRequireDefault(_link);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

exports.default = function () {
  return _react2.default.createElement(
    'div',
    { className: 'nav-items' },
    _react2.default.createElement(
      _link2.default,
      { href: '/about-me' },
      _react2.default.createElement(
        'a',
        null,
        'about-me'
      )
    ),
    _react2.default.createElement(
      _link2.default,
      { href: '/articles' },
      _react2.default.createElement(
        'a',
        null,
        'articles'
      )
    ),
    _react2.default.createElement(
      _link2.default,
      { href: '/talks-projects' },
      _react2.default.createElement(
        'a',
        null,
        'talks-and-projects'
      )
    ),
    _react2.default.createElement(
      _link2.default,
      { href: '/musts' },
      _react2.default.createElement(
        'a',
        null,
        'musts'
      )
    )
  );
};