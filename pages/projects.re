let projects: list(Project.project) = [
  {
    title: {js|⬆️ Subilo|js},
    tags: ["Rust", "CI/CD"],
    repo: "https://github.com/Huemul/suilo",
    url: Some("https://subilo.io"),
    description: {js|Deployment automation agent|js},
    isExternal: false,
  },
  {
    title: {js|🔗 tsplay.dev|js},
    tags: ["typescript", "dev tools"],
    repo: "https://github.com/gillchristian/tsplay.dev",
    url: Some("https://tsplay.dev"),
    description: {js|A link shortener for the TypeScript Playground sharable links|js},
    isExternal: false,
  },
  {
    title: {js|🔍 tsearch.io|js},
    tags: ["typescript", "dev tools"],
    repo: "https://github.com/gillchristian/ts-earch",
    url: Some("https://tsearch.io"),
    description: {js|Search TypeScript functions and methods by types|js},
    isExternal: false,
  },
  {
    title: {js|🥑 literate-avocado|js},
    tags: ["elm", "GitHub API", "productivity"],
    repo: "https://github.com/gillchristian/literate-avocado",
    url: Some("https://gillchristian.github.io/literate-avocado/"),
    description: {js|A GitHub Gist explorer app|js},
    isExternal: false,
  },
  {
    title: {js|🌍 webout|js},
    tags: ["terminal", "cli", "golang"],
    url: Some("https://webout.xyz"),
    repo: "https://github.com/gillchristian/webout",
    description: {js|Pipe terminal output to the browser|js},
    isExternal: false,
  },
  {
    title: "io-ts-reporters",
    tags: ["TypeScript", "fp-ts", "io-ts"],
    url: Some("https://gillchristian.github.io/io-ts-reporters"),
    repo: "https://github.com/gillchristian/io-ts-reporters",
    description: {js|Error reporters for io-ts|js},
    isExternal: false,
  },
  {
    title: {js|🐹 castor|js},
    tags: ["GitHub", "git", "cli", "golang"],
    repo: "https://github.com/moondewio/castor",
    url: None,
    description: {js|Review GitHub PRs and go back where you left of|js},
    isExternal: false,
  },
  {
    title: "remote-data-ts",
    tags: ["typescript"],
    repo: "https://github.com/gillchristian/remote-data-ts",
    url: None,
    description: {js|Types and utilities to represent the states of fetched data|js},
    isExternal: false,
  },
  {
    title: "trae",
    tags: ["fetch", "http", "api"],
    repo: "https://github.com/huemul/trae",
    url: None,
    description: {js|Fetch based HTTP client for Node & the browser|js},
    isExternal: false,
  },
  {
    title: "safe-redux-ts",
    tags: ["typescript", "redux", "useReducer"],
    repo: "https://github.com/gillchristian/safe-redux-ts",
    url: None,
    description: {js|Safely create and handle Redux (and useReducer) actions|js},
    isExternal: false,
  },
  {
    title: "@housinganywhere/match",
    tags: ["typescript"],
    repo: "https://github.com/housinganywhere/match",
    url: None,
    description: {js|poor man's pattern matching|js},
    isExternal: false,
  },
  {
    title: "todos",
    tags: ["haskell", "cli", "productivity"],
    repo: "https://github.com/gillchristian/todos",
    url: None,
    description: {js|A CLI app for managing daily to do's|js},
    isExternal: false,
  },
  {
    title: "dir_alias",
    tags: ["bash", "zsh"],
    repo: "https://github.com/moondewio/dir_alias",
    url: None,
    description: {js|Directory based aliases|js},
    isExternal: false,
  },
  {
    title: "skratch",
    tags: ["react", "service-worker", "notes", "draft-js", "PWA"],
    url: Some("https://skratch.xyz"),
    repo: "https://github.com/gillchristian/scratch",
    description: {js|Minimalistic notes app|js},
    isExternal: false,
  },
  {
    title: "rl",
    tags: ["golang", "cli"],
    repo: "https://github.com/gillchristian/rl",
    url: None,
    description: {js|FIFO reading list CLI tool|js},
    isExternal: false,
  },
  {
    title: "dadjokes",
    tags: ["node", "javascript", "cli"],
    repo: "https://github.com/gillchristian/dadjokes",
    url: None,
    description: {js|/r/dadjokes front-page in your terminal|js},
    isExternal: false,
  },
  {
    title: "generator-api",
    tags: ["express", "mongodb", "mongoose", "docker"],
    url: Some("https://ndelvalle.github.io/generator-api/"),
    repo: "https://github.com/ndelvalle/generator-api",
    description: {js|Yeoman generator for creating RESTful NodeJS APIs, using ES6, Mongoose and Express.|js},
    isExternal: true,
  },
  {
    title: "chimi",
    tags: ["markdown", "runner", "javascript", "snippets"],
    repo: "https://github.com/Huemul/chimi",
    url: None,
    description: {js|Run JavaScript snippets from your markdown files|js},
    isExternal: false,
  },
];

let render_project = (project: Project.project) =>
  <Project key={project.title} project />;

[@react.component]
let make = () =>
  <div className="Site">
    <Nav />
    <div className="Site-content">
      <blockquote>
        <p>
          {
            ReasonReact.string(
              "Don't be a boilerplate programmer. Instead, build tools for users and other programmers. Take historical note of the textile and steel industries:",
            )
          }
        </p>
        <p>
          {
            ReasonReact.string(
              "Do you want to build machines and tools, or do you want to operate those machines?",
            )
          }
        </p>
        <p> <i> {ReasonReact.string("Ras Bodic.")} </i> </p>
      </blockquote>
      <h1> {ReasonReact.string("Open Source Projects")} </h1>
      <div>
        {
          projects
          |> List.map(render_project)
          |> Array.of_list
          |> ReasonReact.array
        }
      </div>
    </div>
    <Footer />
  </div>;

let default = make;
