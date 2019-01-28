In December last year I created the proof of concept (PoC) for an idea I have
that seems a bit crazy, at least to me now. It’s a tool to search TypeScript
functions and methods by their type signature.

Since I am quite happy with this PoC I decied to commit to the project and work
on developing a real useful version.

I plan to share my experiece in this devlog because I want to keep track of how
the project evolves and what I learn and the things I discover along the way.
Also, I guess it will be interesting and useful to others too. To get started I
think it makes sense to share how I came up with this idea, what I’ve done
already and what is ahead.

<p>
<div class="centered">
  ![Crazy idea](https://i.imgur.com/dFJAhnT.jpg)
  <i class="epilogue">A crazy idea.</i>
</div>
</p>

## The crazy idea

I have been learning about functional programming for a while now. I started
with [Professor Frisby's Mostly Adequate Guide to Functional Programming][1] and
then went on to try out different languages, Elm, Haskell, Reason, Clojure,
Scheme. Which is something I enjoy on itself and encourage you to do too.
Learning other languages will give you new approaches and ways to solve problems
that you can bring back to the language/s you use.

While playing around with Haskell for last year’s [Advent of Code][2] I used
[Hoogle][3] (yeah, Hoogle, with H) a lot.

> Hoogle is a Haskell API search engine, which allows you to search the Haskell
> libraries on Stackage by either function name, or by approximate type
> signature.

[Stackage][4] is a package manager for Haskell, with the guarantee that packages
will work with each other.

Hoogle turned out to be a really useful tool during development. Which begged
the question, why isn’t there such thing for TypeScript? I work with TypeScript
on a daily basis and I think it would be a really good addition to the avaliable
tools.

The closest thing I found is [Open Symbol by name][5] in VS Code.

## The proof of concept

I shared the idea with my friend [Franco][6], who is much more pragmatic than I
am, and he told my “Why don’t you build a proof of concept and see if it makes
sense?”.

As a good proof of concept it had to be as simple as possible. A way to extract
the type signatures from all the exported functions in a local directory and
search them trough a simple UI.

You can find it [here][7]. For now there is not much you can do with it and
documentation is very basic.

<div class="iframe-container">
<iframe
  class="iframe"
  src="https://www.youtube.com/embed/Gf5irOLIFX8"
  frameborder="0"
  allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture"
  allowfullscreen>
</iframe>
</div>

By the way, I should give credit for the name, `ts-earch`, to Franco.

## Open questions

Developing the PoC convinced me that it is an idea worth to work on. But, to be
honest, it also left me more questions than answers.

- Should I use actual TypeScript type signatures for search? Or should I come up
  with a simpler DSL? In Haskell that is not so much of a problem. Let’s compare
  the signature of `compose` in both languages.

```haskell
compose :: (b -> c) -> (a -> b) -> a -> c
```

```ts
type Compose = <A, B, C>(f: (b: B) => C, g: (a: A) => B) => (a: A) => C
```

- What about type inference? Say we have a `Person` type, and a function that
  accepts a person, defined as:

```ts
interface Person {
  name: string
}

const getName = (p: Person) => p.name
```

Searching for `(x: { name: string }) => string` should retun `getName` even
though the type matches implicitly. How to solve that, I have no idea yet.

- What is the best way to index the types for searching them?
- How to weigh and match types when searching?

These are a few of the open questions I have that I will have to solve. And I am
sure there will be more questions along the way.

<p>
<div class="centered">
  ![The road ahead](https://i.imgur.com/MGsrYzU.jpg)
  <i class="epilogue">The road ahead, definitely not a clear path.</i>
</div>
</p>

## One step at a time

To get started it makes sense to have something that people can use and
experient with. My short term goal is to adjust a few things and deploy
`ts-earch` with all the [DefinitelyTyped][8] packages avaliable for search.

If you have any questions, suggestions or would like to collaborate on the
projec feel free to [reach out to me on Twitter][9].

Stay tunned for more updates =D

---

**P.S.**: for the next devlop I will either update my website to allow
commenting and sharing or give up and publish on Medium.

---

[1]: https://github.com/MostlyAdequate/mostly-adequate-guide
[2]: https://adventofcode.com
[3]: https://hoogle.haskell.org/
[4]: https://www.stackage.org/

<!-- prettier-ignore -->
[5]: https://code.visualstudio.com/docs/editor/editingevolved#_open-symbol-by-name
[6]: https://github.com/fvictorio

<!-- prettier-ignore -->
[7]: https://github.com/gillchristian/ts-earch/tree/68b515b99076460e25e70c545ab6a6397100f77d
[8]: https://github.com/DefinitelyTyped/DefinitelyTyped
[9]: https://twitter.com/gillchristian
