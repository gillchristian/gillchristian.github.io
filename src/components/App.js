import React, {PropTypes} from 'react'
import Head from 'next/head'

const App = ({children}) => {
  easterEgg()
  return (
    <div>
      <Head>
        <link rel="manifest" href="/static/manifest.json" />
        <title>Christian Gill</title>
        <meta charSet="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
        <meta name="description" content="Christian Gill" />
        <meta name="keywords" content="web-developer, developer, javascript, html, angular, react, node" />
        <meta name="author" content="gillchristian" />
        <link rel="shortcut icon" href="/static/images/favicon.ico" />

        <link rel="stylesheet" href="/static/hack/hack.css" />
        <link rel="stylesheet" href="/static/style.css" />
        <link
          href="https://maxcdn.bootstrapcdn.com/font-awesome/4.6.3/css/font-awesome.min.css"
          rel="stylesheet"
          integrity="sha384-T8Gy5hrqNKT+hzMclPo118YTQO6cYprQmhrYwIiQ/3axmI1hQomh7Ud2hPOy8SP1"
          crossOrigin="anonymous"
        />
      </Head>
      {children}
    </div>
  )
}

App.propTypes = {
  children: PropTypes.node,
}

export default App

function easterEgg() {
  // eslint-disable-next-line max-len
  console.log('%cYou should not be here, this is just for developers!!!', 'color: red; font-size:30px; font-family: "Helvetica",sans-serif;')
  // eslint-disable-next-line max-len
  console.log('%cOhh wait you are a developer, its OK then ¯\\_(ツ)_/¯', 'font-size:25px; font-family: "Helvetica",sans-serif; background: -webkit-linear-gradient(left, blue, cyan); -webkit-background-clip: text; -webkit-text-fill-color: transparent;')
}
