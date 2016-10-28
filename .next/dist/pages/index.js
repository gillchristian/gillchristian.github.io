'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});

var _react = require('/home/altoros/Documents/dev/gillchristian.github.io/node_modules/react/react.js');

var _react2 = _interopRequireDefault(_react);

var _App = require('../src/components/App');

var _App2 = _interopRequireDefault(_App);

var _NavBar = require('../src/components/NavBar');

var _NavBar2 = _interopRequireDefault(_NavBar);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

exports.default = function () {
  return _react2.default.createElement(
    _App2.default,
    null,
    _react2.default.createElement(
      'div',
      { className: 'home' },
      _react2.default.createElement(
        'h1',
        { className: 'title' },
        'Christian Gill'
      ),
      _react2.default.createElement(_NavBar2.default, null)
    )
  );
};