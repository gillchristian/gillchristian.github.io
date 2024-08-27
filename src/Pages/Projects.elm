module Pages.Projects exposing (page)

import Components.Header exposing (Page(..))
import Components.Sidebar
import Components.Tags as Tags
import Html exposing (Html)
import Html.Attributes as Attr
import View exposing (View)



-- TODO:
-- - Update the projects list
-- - Split into OSS and other projects
-- - Improve the view (maybe like bansco.github.io?)


page : View msg
page =
    Components.Sidebar.view
        Projects
        { page =
            { title = "Projects"
            , body =
                [ quote
                , Html.h1 [] [ Html.text "Open Source Projects" ]
                , Html.div
                    []
                  <|
                    List.map project projects
                ]
            }
        }


quote : Html msg
quote =
    Html.blockquote
        []
        [ Html.p
            []
            [ Html.text "Don't be a boilerplate programmer. Instead, build tools for users and other programmers. "
            , Html.text "Take historical note of the textile and steel industries:"
            ]
        , Html.p
            []
            [ Html.text "Do you want to build machines and tools, or do you want to operate those machines?" ]
        , Html.p
            []
            [ Html.i [] [ Html.text "Ras Bodic." ] ]
        ]


type alias Project =
    { title : String
    , techs : List String
    , repo : String -- TODO: use the same `urls` pattern as in `Talks`
    , url : Maybe String
    , description : String
    , isExternal : Bool
    }


project : Project -> Html msg
project p =
    Html.div
        [ Attr.class "project" ]
        [ Html.p
            []
            [ Html.b [ Attr.class "project-title" ] [ Html.text p.title ]
            , Html.small
                []
                [ if p.isExternal then
                    Html.text " (contributor) "

                  else
                    Html.text ""
                ]
            ]
        , Html.p [] [ Html.text p.description ]
        , Html.small [] [ Tags.view p.techs ]
        , Html.p [] <|
            Html.a
                [ Attr.href p.repo
                , Attr.target "_blank"
                , Attr.rel ""
                ]
                [ Html.text "repo" ]
                :: (case p.url of
                        Just url ->
                            [ Html.text " | "
                            , Html.a
                                [ Attr.href url
                                , Attr.target "_blank"
                                , Attr.rel ""
                                ]
                                [ Html.text "view" ]
                            ]

                        Nothing ->
                            []
                   )
        ]


projects : List Project
projects =
    [ { title = "rustdis"
      , techs = [ "Rust", "Redis" ]
      , repo = "https://github.com/ndelvalle/rustdis"
      , url = Just "https://x.com/gillchristian/status/1784527143952609395"
      , description = "Partial Redis server implementation using Rust. For learning purposes."
      , isExternal = True
      }
    , { title = "ScriptureStudy"
      , techs = [ "TypeScript", "React" ]
      , repo = "https://github.com/gillchristian/ScriptureStudy"
      , url = Just "https://x.com/gillchristian/status/1618157855974260736"
      , description = "My own Bible, with a developer's twist"
      , isExternal = False
      }
    , { title = "Listas"
      , techs = [ "PureScript", "Halogen", "Tailwind" ]
      , repo = "https://github.com/gillchristian/listas-web"
      , url = Just "https://listas.io"
      , description = "Reading lists manager"
      , isExternal = False
      }
    , { title = "🔗 tsplay.dev"
      , techs = [ "typescript", "dev tools" ]
      , repo = "https://github.com/gillchristian/tsplay.dev"
      , url = Just "https://tsplay.dev"
      , description = "A link shortener for the TypeScript Playground sharable links"
      , isExternal = False
      }
    , { title = "twpurs"
      , techs = [ "Haskell", "PureScript", "Tailwind" ]
      , repo = "https://github.com/gillchristian/tailwind-purs"
      , url = Nothing
      , description = "Type safe Tailwind for PureScript Halogen"
      , isExternal = False
      }
    , { title = "🔍 tsearch.io"
      , techs = [ "typescript", "dev tools" ]
      , repo = "https://github.com/gillchristian/ts-earch"
      , url = Just "https://tsearch.io"
      , description = "Search TypeScript functions and methods by types"
      , isExternal = False
      }
    , { title = "⬆️ Subilo"
      , techs = [ "Rust", "CI/CD" ]
      , repo = "https://github.com/Huemul/suilo"
      , url = Nothing
      , -- "https://subilo.io" is down
        description = "Deployment automation agent"
      , isExternal = False
      }
    , { title = "🥑 literate-avocado"
      , techs = [ "elm", "GitHub API", "productivity" ]
      , repo = "https://github.com/gillchristian/literate-avocado"
      , url = Just "https://gillchristian.github.io/literate-avocado/"
      , description = "A GitHub Gist explorer app"
      , isExternal = False
      }
    , { title = "🌍 webout"
      , techs = [ "terminal", "cli", "golang" ]
      , url = Just "https://webout.xyz"
      , repo = "https://github.com/gillchristian/webout"
      , description = "Pipe terminal output to the browser"
      , isExternal = False
      }
    , { title = "io-ts-reporters"
      , techs = [ "TypeScript", "fp-ts", "io-ts" ]
      , url = Just "https://gillchristian.github.io/io-ts-reporters"
      , repo = "https://github.com/gillchristian/io-ts-reporters"
      , description = "Error reporters for io-ts"
      , isExternal = False
      }
    , { title = "🐹 castor"
      , techs = [ "GitHub", "git", "cli", "golang" ]
      , repo = "https://github.com/moondewio/castor"
      , url = Nothing
      , description = "Review GitHub PRs and go back where you left of"
      , isExternal = False
      }
    , { title = "remote-data-ts"
      , techs = [ "typescript" ]
      , repo = "https://github.com/gillchristian/remote-data-ts"
      , url = Nothing
      , description = "Types and utilities to represent the states of fetched data"
      , isExternal = False
      }
    , { title = "trae"
      , techs = [ "fetch", "http", "api" ]
      , repo = "https://github.com/huemul/trae"
      , url = Nothing
      , description = "Fetch based HTTP client for Node & the browser"
      , isExternal = False
      }
    , { title = "safe-redux-ts"
      , techs = [ "typescript", "redux", "useReducer" ]
      , repo = "https://github.com/gillchristian/safe-redux-ts"
      , url = Nothing
      , description = "Safely create and handle Redux (and useReducer) actions"
      , isExternal = False
      }
    , { title = "@housinganywhere/match"
      , techs = [ "typescript" ]
      , repo = "https://github.com/housinganywhere/match"
      , url = Nothing
      , description = "poor man's pattern matching"
      , isExternal = False
      }
    , { title = "todos"
      , techs = [ "haskell", "cli", "productivity" ]
      , repo = "https://github.com/gillchristian/todos"
      , url = Nothing
      , description = "A CLI app for managing daily to do's"
      , isExternal = False
      }
    , { title = "dir_alias"
      , techs = [ "bash", "zsh" ]
      , repo = "https://github.com/moondewio/dir_alias"
      , url = Nothing
      , description = "Directory based aliases"
      , isExternal = False
      }
    , { title = "skratch"
      , techs = [ "react", "service-worker", "notes", "draft-js", "PWA" ]
      , url = Just "https://skratch.xyz"
      , repo = "https://github.com/gillchristian/scratch"
      , description = "Minimalistic notes app"
      , isExternal = False
      }
    , { title = "rl"
      , techs = [ "golang", "cli" ]
      , repo = "https://github.com/gillchristian/rl"
      , url = Nothing
      , description = "FIFO reading list CLI tool"
      , isExternal = False
      }
    , { title = "dadjokes"
      , techs = [ "node", "javascript", "cli" ]
      , repo = "https://github.com/gillchristian/dadjokes"
      , url = Nothing
      , description = "/r/dadjokes front-page in your terminal"
      , isExternal = False
      }
    , { title = "generator-api"
      , techs = [ "express", "mongodb", "mongoose", "docker" ]
      , url = Just "https://ndelvalle.github.io/generator-api/"
      , repo = "https://github.com/ndelvalle/generator-api"
      , description = "Yeoman generator for creating RESTful NodeJS APIs, using ES6, Mongoose and Express."
      , isExternal = True
      }
    , { title = "chimi"
      , techs = [ "markdown", "runner", "javascript", "snippets" ]
      , repo = "https://github.com/Huemul/chimi"
      , url = Nothing
      , description = "Run JavaScript snippets from your markdown files"
      , isExternal = False
      }
    ]
