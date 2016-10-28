'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});

var _react = require('/home/altoros/Documents/dev/gillchristian.github.io/node_modules/react/react.js');

var _react2 = _interopRequireDefault(_react);

var _head = require('/home/altoros/Documents/dev/gillchristian.github.io/node_modules/next/dist/lib/head.js');

var _head2 = _interopRequireDefault(_head);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var App = function App(_ref) {
  var children = _ref.children;

  easterEgg();
  return _react2.default.createElement(
    'div',
    null,
    _react2.default.createElement(
      _head2.default,
      null,
      _react2.default.createElement('link', { rel: 'manifest', href: '/static/manifest.json' }),
      _react2.default.createElement(
        'title',
        null,
        'Christian Gill'
      ),
      _react2.default.createElement('meta', { charSet: 'utf-8' }),
      _react2.default.createElement('meta', { name: 'viewport', content: 'width=device-width, initial-scale=1' }),
      _react2.default.createElement('meta', { name: 'description', content: 'Christian Gill' }),
      _react2.default.createElement('meta', { name: 'keywords', content: 'web-developer, developer, javascript, html, angular, react, node' }),
      _react2.default.createElement('meta', { name: 'author', content: 'gillchristian' }),
      _react2.default.createElement('link', { rel: 'shortcut icon', href: '/static/images/favicon.ico' }),
      _react2.default.createElement('link', { rel: 'stylesheet', href: '/static/hack/hack.css' }),
      _react2.default.createElement('link', { rel: 'stylesheet', href: '/static/style.css' }),
      _react2.default.createElement('link', {
        href: 'https://maxcdn.bootstrapcdn.com/font-awesome/4.6.3/css/font-awesome.min.css',
        rel: 'stylesheet',
        integrity: 'sha384-T8Gy5hrqNKT+hzMclPo118YTQO6cYprQmhrYwIiQ/3axmI1hQomh7Ud2hPOy8SP1',
        crossOrigin: 'anonymous'
      })
    ),
    children
  );
};

App.propTypes = {
  children: _react.PropTypes.node
};

exports.default = App;


function easterEgg() {
  // eslint-disable-next-line max-len
  console.log('%cYou should not be here, this is just for developers!!!', 'color: red; font-size:30px; font-family: "Helvetica",sans-serif;');
  // eslint-disable-next-line max-len
  console.log('%cOhh wait you are a developer, its OK then ¯\\_(ツ)_/¯', 'font-size:25px; font-family: "Helvetica",sans-serif; background: -webkit-linear-gradient(left, blue, cyan); -webkit-background-clip: text; -webkit-text-fill-color: transparent;');
}