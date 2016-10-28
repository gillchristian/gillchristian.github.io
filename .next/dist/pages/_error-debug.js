'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});

var _inherits2 = require('/home/altoros/Documents/dev/gillchristian.github.io/node_modules/babel-runtime/helpers/inherits');

var _inherits3 = _interopRequireDefault(_inherits2);

var _getPrototypeOf = require('/home/altoros/Documents/dev/gillchristian.github.io/node_modules/babel-runtime/core-js/object/get-prototype-of');

var _getPrototypeOf2 = _interopRequireDefault(_getPrototypeOf);

var _classCallCheck2 = require('/home/altoros/Documents/dev/gillchristian.github.io/node_modules/babel-runtime/helpers/classCallCheck');

var _classCallCheck3 = _interopRequireDefault(_classCallCheck2);

var _createClass2 = require('/home/altoros/Documents/dev/gillchristian.github.io/node_modules/babel-runtime/helpers/createClass');

var _createClass3 = _interopRequireDefault(_createClass2);

var _possibleConstructorReturn2 = require('/home/altoros/Documents/dev/gillchristian.github.io/node_modules/babel-runtime/helpers/possibleConstructorReturn');

var _possibleConstructorReturn3 = _interopRequireDefault(_possibleConstructorReturn2);

var _react = require('/home/altoros/Documents/dev/gillchristian.github.io/node_modules/react/react.js');

var _react2 = _interopRequireDefault(_react);

var _stripAnsi = require('strip-ansi');

var _stripAnsi2 = _interopRequireDefault(_stripAnsi);

var _head = require('/home/altoros/Documents/dev/gillchristian.github.io/node_modules/next/dist/lib/head.js');

var _head2 = _interopRequireDefault(_head);

var _css = require('/home/altoros/Documents/dev/gillchristian.github.io/node_modules/next/dist/lib/css.js');

var _css2 = _interopRequireDefault(_css);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var ErrorDebug = function (_React$Component) {
  (0, _inherits3.default)(ErrorDebug, _React$Component);

  function ErrorDebug() {
    (0, _classCallCheck3.default)(this, ErrorDebug);
    return (0, _possibleConstructorReturn3.default)(this, (ErrorDebug.__proto__ || (0, _getPrototypeOf2.default)(ErrorDebug)).apply(this, arguments));
  }

  (0, _createClass3.default)(ErrorDebug, [{
    key: 'render',
    value: function render() {
      var _props = this.props,
          message = _props.message,
          path = _props.path;


      return _react2.default.createElement(
        'div',
        { className: styles.errorDebug },
        _react2.default.createElement(
          _head2.default,
          null,
          _react2.default.createElement('style', { dangerouslySetInnerHTML: { __html: '\n          body {\n            background: #dc0067;\n            margin: 0;\n          }\n        ' } })
        ),
        _react2.default.createElement(
          'div',
          { className: styles.heading },
          'Error in ',
          path
        ),
        _react2.default.createElement(
          'pre',
          { className: styles.message },
          (0, _stripAnsi2.default)(message)
        )
      );
    }
  }], [{
    key: 'getInitialProps',
    value: function getInitialProps(_ref) {
      var err = _ref.err;
      var message = err.message,
          module = err.module;

      return { message: message, path: module.rawRequest };
    }
  }]);
  return ErrorDebug;
}(_react2.default.Component);

exports.default = ErrorDebug;


var styles = {
  body: (0, _css2.default)({
    background: '#dc0067',
    margin: 0
  }),

  errorDebug: (0, _css2.default)({
    height: '100%',
    padding: '16px',
    boxSizing: 'border-box'
  }),

  message: (0, _css2.default)({
    fontFamily: 'menlo-regular',
    fontSize: '10px',
    color: '#fff',
    margin: 0
  }),

  heading: (0, _css2.default)({
    fontFamily: 'sans-serif',
    fontSize: '13px',
    fontWeight: 'bold',
    color: '#ff90c6',
    marginBottom: '20px'
  })
};