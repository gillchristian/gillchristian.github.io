const path = require('path')
const webpack = require('webpack')

const nodeEnv = process.env.NODE_ENV || 'development'
const isProd = nodeEnv === 'production'

module.exports = {
  devtool: isProd ? 'hidden-source-map' : 'cheap-eval-source-map',
  entry: {
    bundle: ['babel-polyfill', './src/index.js'],
  },
  output: {
    path: path.join(__dirname, 'public', 'assets', 'js'),
    filename: '[name].js',
  },
  module: {
    loaders: [
      {
        test: /\.(js|jsx)$/,
        exclude: /node_modules/,
        loaders: ['babel-loader'],
      },
    ],
  },
  resolve: {
    extensions: ['.js'],
    modules: ['src', 'node_modules'],
  },
  plugins: [
    new webpack.LoaderOptionsPlugin({ minimize: true, debug: false }),
    new webpack.optimize.UglifyJsPlugin({
      compress: {
        warnings: false,
      },
      output: {
        comments: false,
      },
      sourceMap: false,
    }),
    new webpack.DefinePlugin({
      'process.env': {
        NODE_ENV: JSON.stringify(nodeEnv),
      },
    }),
  ],
}
