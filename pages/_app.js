import App from "next/app"
import Head from "next/head"
import React from "react"

const names = {
  "/articles": "Articles | Christian Gill",
  "/about": "About | Christian Gill",
  "/talks": "Talks | Christian Gill",
  "/projects": "Projects | Christian Gill",
}

const pageTitle = (route) => {
  const maybeMatch = Object.entries(names).find(([path]) =>
    route.startsWith(path),
  )

  const [, title] = maybeMatch || ["/", "Christian Gill"]

  return title
}

export default class MyApp extends App {
  render() {
    const {router, pageProps} = this.props

    return (
      <>
        <Head>
          <title>{pageTitle(router.route)}</title>
          <link rel="stylesheet" type="text/css" href="/styles.css" />
        </Head>
        <this.props.Component {...pageProps} />
      </>
    )
  }
}
