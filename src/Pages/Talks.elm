module Pages.Talks exposing (page)

import Components.Header exposing (Page(..))
import Components.Sidebar
import Html exposing (Html)
import Html.Attributes as Attr
import View exposing (View)


page : View msg
page =
    Components.Sidebar.view
        Talks
        { page =
            { title = "Pages.Talks"
            , body =
                [ quote
                , Html.h1 [] [ Html.text "Talks at meetups & conferences" ]
                , iconsReference
                , Html.div [] <| List.map talk talks
                ]
            }
        }


iconsReference : Html msg
iconsReference =
    Html.div
        [ Attr.class "talks-icons-reference" ]
        [ Html.span [] [ Html.text <| talkIcon Conference, Html.text " Conference" ]
        , Html.span [] [ Html.text <| talkIcon Meetup, Html.text " Meetup" ]
        , Html.span [] [ Html.text <| talkIcon Lightning, Html.text " Lightning talk" ]
        , Html.span [] [ Html.text <| talkIcon Workshop, Html.text " Workshop" ]
        , Html.span [] [ Html.text <| talkIcon Podcast, Html.text " Podcast" ]
        ]


quote : Html msg
quote =
    Html.blockquote
        []
        [ Html.p [] [ Html.text "I would like to be able to always divide the things up into as many pieces as I can, each of which I understand separately." ]
        , Html.p [] [ Html.text "I would like to understand the way of adding things up, independently of what it is I'm adding up." ]
        , Html.p [] [ Html.i [] [ Html.text "Gerald Sussman" ] ]
        ]


type TalkType
    = Meetup
    | Conference
    | Lightning
    | Podcast
    | Workshop


talkIcon : TalkType -> String
talkIcon t =
    case t of
        Meetup ->
            "💬"

        Conference ->
            "🔊"

        Lightning ->
            "⚡"

        Podcast ->
            "🎙"

        Workshop ->
            "👨\u{200D}🏫"


type alias Talk =
    { title : String
    , event : String
    , eventUrl : String
    , description : String
    , date : String
    , links : List { url : String, label : String }
    , type_ : TalkType
    }


talk : Talk -> Html msg
talk t =
    Html.div
        [ Attr.class "talk" ]
        [ Html.p [ Attr.class "talk-title" ]
            [ Html.text <| talkIcon t.type_
            , Html.text " "
            , Html.b [] [ Html.text t.title ]
            ]
        , Html.p
            []
            [ Html.a
                [ Attr.href t.eventUrl
                , Attr.rel "noopener noreferrer"
                , Attr.target "_blank"
                ]
                [ Html.text t.event ]
            , Html.text " - "
            , Html.text t.date
            ]
        , Html.p
            []
            [ Html.text t.description ]
        , if List.length t.links > 0 then
            t.links
                |> List.map
                    (\link ->
                        Html.a
                            [ Attr.href link.url
                            , Attr.rel "noopener noreferrer"
                            , Attr.target "_blank"
                            ]
                            [ Html.text link.label ]
                    )
                |> List.intersperse (Html.text " | ")
                |> Html.p []

          else
            Html.text ""
        ]


talks : List Talk
talks =
    [ { title = "Maps of the Codebase"
      , event = "AmsterdamJS Meetup"
      , eventUrl = "https://www.meetup.com/amsterdamjs/events/298560630"
      , description = "Inspired by Peter Turchi's book, I compare cartography to technical writing, showing how effective writing guides developers through a codebase like a map."
      , date = "March 2024"
      , links = []
      , type_ = Meetup
      }
    , { title = "A day in the life of a Software Engineer"
      , event = "Software Engineering Summit 2022 ELU"
      , eventUrl = "https://techmindssummit.com/"
      , description = "What's like to work as a software engineer? In a nutshell you'll write code to solve problems and collaborate on meetings. Of course it's more complicated than that."
      , date = "June 2022"
      , links =
            [ { url = "https://youtu.be/CADONAsk1Zw?t=10627", label = "Video" }
            , { url = "https://collectednotes.com/gillchristian/a-day-in-the-life-of-a-software-engineer"
              , label = "Notes"
              }
            ]
      , type_ = Podcast
      }
    , { title = "A Software Engineer's Experience with the Benefits of Using TypeScript"
      , event = "OfferZen Podcast"
      , eventUrl = "https://www.offerzen.com/blog/software-engineers-experience-benefits-typescript"
      , description = "A chat with Jomiro on why I enjoy working with TypeScript, some of the benefits and advice for those gettings started"
      , date = "August 2020"
      , links =
            [ { url = "https://www.offerzen.com/blog/software-engineers-experience-benefits-typescript"
              , label = "Podcast"
              }
            , { url = "https://www.youtube.com/watch?v=wQLNyvigZ1M", label = "Video" }
            ]
      , type_ = Podcast
      }
    , { title = "Modeling your way to consistency"
      , event = "Frontend at Catawiki"
      , eventUrl = "https://www.meetup.com/javascript-workshops-amsterdam/events/270592994/"
      , description = "How domain modeling can help us to make our apps consistent & safe"
      , date = "May 2020"
      , links =
            [ { url = "https://modeling-ts.now.sh", label = "Slides" }
            , { url = "https://github.com/gillchristian/modeling-talk"
              , label = "Slides (repo)"
              }
            ]
      , type_ = Meetup
      }
    , { title = "Modeling your way to consistency"
      , event = "dotJS"
      , eventUrl = "https://dotjs.io"
      , description = "How domain modeling can help us to make our apps consistent & safe"
      , date = "December 2019"
      , links =
            [ { url = "https://www.dotconferences.com/2019/12/christian-gill-modeling-your-way-to-consistency"
              , label = "Stream"
              }
            , { url = "https://bit.ly/dotjs-modeling", label = "Slides" }
            , { url = "https://github.com/gillchristian/modeling-lightning"
              , label = "Slides (repo)"
              }
            ]
      , type_ = Lightning
      }
    , { title = "FP For The People (v2)"
      , event = "OdessaJS"
      , eventUrl = "http://odessajs.org/"
      , description = "Core principles of FP and why to use it on JS"
      , date = "July 2019"
      , links =
            [ { url = "https://www.youtube.com/watch?v=0GDkkun8jDQ", label = "Stream" }
            , { url = "https://fp-for-the-people-light.gillchristian.now.sh/"
              , label = "Slides (updated)"
              }
            , { url = "https://github.com/gillchristian/fp-for-the-people-v2"
              , label = "Slides (repo)"
              }
            ]
      , type_ = Conference
      }
    , { title = "FP for the People"
      , event = "Javascript Litoral Meetup"
      , eventUrl = "https://www.meetup.com/js-litoral/events/241974602/"
      , description = "Core principles of FP and why to use it on JS"
      , date = "July 2017"
      , links =
            [ { url = "https://gillchristian.xyz/fp-in-js", label = "Slides" }
            , { url = "https://www.youtube.com/watch?v=WIl921KAX0g", label = "Stream" }
            ]
      , type_ = Meetup
      }
    , { title = "React, UI con esteroides"
      , event = "Javascript Litoral Meetup"
      , eventUrl = "https://www.meetup.com/js-litoral/events/235803581/"
      , description = "Introduction to UI development with React"
      , date = "Nov 2016"
      , links =
            [ { url = "https://gillchristian.xyz/react-intro", label = "Slides" }
            , { url = "https://github.com/javascript-litoral/react-intro"
              , label = "Repo"
              }
            , { url = "https://javascript-litoral.github.io/react-intro"
              , label = "Demo app"
              }
            , { url = "https://youtu.be/REPQDmYnYPk?t=48m2s", label = "Stream" }
            ]
      , type_ = Meetup
      }
    , { title = "Developing with GIT"
      , event = "CISL 2016 - UTN - Santa Fe"
      , eventUrl = "http://cisl.org.ar/cronograma/10-cisl2016-dia4-santa-fe-utn#.WBHYlMIrLQo"
      , description = "Introduction to versioning code with GIT, as part of the \"Introduction to software development\" talk."
      , date = "Oct 2016"
      , links =
            [ { url = "https://gillchristian.xyz/git-workshop", label = "Slides" }
            , { url = "https://github.com/gillchristian/git-workshop", label = "Repo" }
            , { url = "https://www.facebook.com/psutnfrsf/videos/1158691657585160/"
              , label = "Stream"
              }
            ]
      , type_ = Workshop
      }
    , { title = "JavaScript ES6"
      , event = "Javascript Litoral Meetup"
      , eventUrl = "http://www.meetup.com/js-Litoral/events/230947251/"
      , description = "EcmaSctip 6 features showcase & usage with Babel."
      , date = "May 2016"
      , links =
            [ { url = "http://slides.com/christiangill/deck", label = "Slides" }
            , { url = "https://github.com/JavascriptLitoral/es6-features"
              , label = "Repo"
              }
            ]
      , type_ = Meetup
      }
    , { title = "Introduction to Angular"
      , event = "Javascript Litoral Meetup"
      , eventUrl = "http://www.meetup.com/js-Litoral/events/229145986/"
      , description = "Introduction to Angular framework, plus some live examples."
      , date = "March 2016"
      , links =
            [ { url = "http://slides.com/christiangill/angular-js-intro"
              , label = "Slides"
              }
            , { url = "https://youtu.be/1qWlIZIar-U?t=5m00s", label = "Stream" }
            , { url = "http://gillchristian.xyz/font-awesome-store/", label = "Demo" }
            , { url = "https://github.com/gillchristian/font-awesome-store"
              , label = "Repo"
              }
            ]
      , type_ = Meetup
      }
    ]
