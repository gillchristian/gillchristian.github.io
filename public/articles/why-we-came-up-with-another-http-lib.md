# Why we came up with another http library

**TL;DR;** we were already using [fetch](https://developer.mozilla.org/en/docs/Web/API/Fetch_API) with some not-so-practical helpers.

I found out about `fetch` a while ago when I was looking for what to use to do HTTP requests on React apps.
Coming from jQuery and Angular this was something I never had to worry about, I would just use what the library/framework provided, and be happy about it.

I get really excited about anything that pushes the web further and makes it better.
And particularly with `fetch`, there are many reasons to get excited about:

- A nice API. _In your face XMLHttpRequest_.
- Request/Response primitives
- `'no-cors'` and opaque responses
- Streams
- Stream readers & cloning
- Headers class
- Cache control
- No-credential `same-origin` requests

You can read about them in depth in [Jake's post](https://jakearchibald.com/2015/thats-so-fetch/).

## Adopting fetch

> It is JS we are talking about, you gotta use the latest stuff, right?

Jokes aside, after trying it out for a little bit with some PoC's, I got the perfect opportunity to use it at work.
I was starting a new project and thanks to the [Github's polyfill](https://github.com/github/fetch), I could already use it safely on those browsers that do not have support yet or will never have. Great!

## Native API cons

Now `fetch` is a native API, and thus is not it's job to provide a library-like interface, with helpers, and shorthand methods.
After some time of using it, I ended up with a bunch of helpers. Like these:

```javascript
// src/utils/fetch-utils.js

export function readOrReject(response) {
  if (!response.ok) {
    throw Error(`${response.status}: ${response.statusText}`)
  }
  return response.json()
}

export function getFetchConfig(method = 'GET', body) {
  const params = {
    headers: {
      'X-CSRF-Token': getUserToken()
    },
    credentials: 'same-origin',
    method
  }

  if (body) {
    params.headers['Content-Type'] = 'application/json'
    params.body = JSON.stringify(body)
  }
  return params
}
```

And this is how every request looked like:

```javascript
// src/api/videos.js

import { getFetchConfig, readOrReject } from '../utils/fetch-utils'

export const getVideos = (id = '') => {
  return fetch('/api/videos/${id}', getFetchConfig())
    .then(readOrReject)
    .then(json => {
      normalizeVideosList(json)
    })
    .catch(err => {
      handleError(err)
    })
}
```

You could say there is nothing wrong with it, but it did not feel right.
I did not want to start another project and straight up copy my `fetch-utils` file.
Neither I liked having a bunch of helpers, which is not bad at all, but I knew I could do better than that.

So I shared my concerns with Nico and he was like _"yo I got the same problems!"_.
After discussing for a while some ideas and wrapping or heads around, we started to write a library.

And that's how we ended up with [trae](https://github.com/huemul/trae).

<div class="centered column">
  ![cool but...](http://i67.tinypic.com/24zx6a8.jpg)
  <span class="caption">cool but...</span>
</div>

## How does it compare to [axios](https://github.com/mzabriskie/axios)?

<!-- no need to load this twice -->
<script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script>

<div class="centered column">

  <blockquote class="twitter-tweet" data-conversation="none" data-lang="en"><p lang="en" dir="ltr"><a href="https://twitter.com/JavaScriptDaily">@JavaScriptDaily</a> Better then axios, or not? :P</p>&mdash; Jonathan Borges (@dev2world) <a href="https://twitter.com/dev2world/status/818824700918898689">January 10, 2017</a></blockquote>
  <blockquote class="twitter-tweet" data-cards="hidden" data-lang="en"><p lang="en" dir="ltr"><a href="https://twitter.com/gillchristian">@gillchristian</a> Hey I like <a href="https://t.co/Al3ZPmeuYM">https://t.co/Al3ZPmeuYM</a>, but I&#39;m asked: &quot;Why use it instead of Axios?&quot;</p>&mdash; malix (@malix) <a href="https://twitter.com/malix/status/818852894397042689">January 10, 2017</a></blockquote>

</div>

Not only a lot of people asked that but we did it ourselves.

Being kind of the default HTTP library it surely influenced us.
Going through its code helped us a lot to understand the needs and internals of an HTTP library and to improve and polish some of our own ideas.
If you want to read well organized, written and documented code check it out. I must admit, I even am a secret fan of [Matt](https://github.com/mzabriskie).

`trae`, like `axios`, is just an HTTP library, and I ~~might be biased here but I~~ would say it is a nice one.
It happens to use `fetch`. So If you are excited about `fetch`, like us, and want to use it, but at the same time want to have the goodies of a library, give `trae` try.

## The name

After going from [Hermes](https://en.wikipedia.org/wiki/Hermes), [Charon](https://en.wikipedia.org/wiki/Charon_(mythology), [Huginn and Muninn](https://en.wikipedia.org/wiki/Huginn_and_Muninn) to famous dogs and even [messenger pigeons](http://www.pigeonracingpigeon.com/uncategorized/famouspigeons/) names we settled up with something simple and even funny.
`trae` [means](https://translate.google.com/#es/en/trae) _brings_ in Spanish, and we felt that for a library that's all about fetching data it was a good fit.

## What's next?

There are some [to-do](https://github.com/huemul/trae#todo) items on the list, but regarding the library itself we like its API and think, even though young, it is already mature enough to say we will not make big breaking changes to it.

That does not mean we are not going to make improvements. We are using `trae` on a daily basis, and are looking for new ways to make it better.
I even have the ~~maybe not so~~ crazy idea of building a dev tools extension with a [bunch of cool stuff](https://github.com/Huemul/trae-chrome-devtools) on it.

We are very open about contributing, so fell free to ask anything or even submit a pull request if you find something to improve.

## Conclusion

Whenever you find a way to improve your workflow take it a step further and make something out of it, whether it is a library, a small module or a tool. 
You will learn a ton in the process, and what's even better you will help many other people. OSS FTW!!!
