module Pages.About exposing (page)

import Components.Header exposing (Page(..))
import Components.Sidebar
import Components.Tags as Tags
import Html exposing (Html)
import Html.Attributes as Attr
import View exposing (View)


page : View msg
page =
    Components.Sidebar.view
        About
        { page =
            { title = "Pages.About"
            , body =
                [ from
                , Html.br [] []
                , stream
                , Html.br [] []
                , dotfiles
                , Html.h2 [] [ Html.text "So far I worked at ..." ]
                ]
                    ++ List.map job jobs
            }
        }


from : Html msg
from =
    Html.p
        []
        [ Html.text "From "
        , Html.a
            [ Attr.href "https://en.wikipedia.org/wiki/Entre_R%C3%ADos_Province"
            , Attr.target "_blank"
            , Attr.rel "noopener noreferrer"
            ]
            [ Html.text "Entre Rios, Argentina" ]
        , Html.text " now living in "
        , Html.a
            [ Attr.href "https://en.wikipedia.org/wiki/Winschoten"
            , Attr.target "_blank"
            , Attr.rel "noopener noreferrer"
            ]
            [ Html.text "Winschoten, The Netherlands" ]
        , Html.text "."
        ]



-- TODO: this should be about Digital Gardens?


stream : Html msg
stream =
    Html.p
        []
        [ Html.text "I code in Rust, Haskell, PureScript, Elm, and Reason "
        , Html.a
            [ Attr.href "/stream" ]
            [ Html.text "when some are watching" ]
        , Html.text ", looking for ways to bring ideas and patterns from strongly typed functional programming into the mainstream. "
        , Html.text "If you have something to share about that I'd be happy to hear."
        ]


dotfiles : Html msg
dotfiles =
    Html.p
        []
        [ Html.text "Also, check my "
        , Html.a
            [ Attr.href "https://github.com/gillchristian/dotfiles"
            , Attr.target "_blank"
            , Attr.rel "noopener noreferrer"
            ]
            [ Html.text "dotfiles" ]
        , Html.text ", every developer should have their dotfiles :)"
        ]


job : Job -> Html msg
job j =
    Html.div
        [ Attr.class "about-job" ]
        [ Html.p
            []
            [ Html.a
                [ Attr.href j.link
                , Attr.target "_blank"
                , Attr.rel "noopener noreferrer"
                , Attr.class "about-job-compan"
                ]
                [ Html.b [] [ Html.text j.company ] ]
            , Html.small [] [ Html.text <| " | " ++ j.from ++ " - " ++ j.to ]
            ]
        , Html.p
            []
          <|
            case j.roles of
                Just roles ->
                    Html.text "As a "
                        :: (List.intersperse (Html.text " and ") <|
                                List.map (\role -> Html.b [] [ Html.text role ]) roles
                           )
                        ++ [ Html.text <| " " ++ j.description ]

                Nothing ->
                    [ Html.text j.description ]
        , Html.small [] [ Tags.view j.techs ]
        ]


type alias Job =
    { company : String
    , link : String
    , roles : Maybe (List String)
    , description : String
    , techs : List String
    , from : String
    , to : String
    }


jobs : List Job
jobs =
    [ { company = "Pinata"
      , link = "https://gopinata.com"
      , roles = Just [ "Senior Software Engineer" ]
      , description = "I help business to achieve data-driven task management"
      , techs =
            [ "Rust"
            , "Elm"
            , "Tailwind"
            , "Haskell"
            , "TypeScript"
            , "Node.js"
            , "React"
            , "AWS"
            ]
      , from = "January 2023"
      , to = "Present"
      }
    , { company = "Scarf"
      , link = "https://scarf.sh"
      , roles = Just [ "Senior Software Engineer" ]
      , description = "helped open-source maintainers connect with their users and deliver better software."
      , techs =
            [ "TypeScript"
            , "Next.js"
            , "Tailwind"
            , "fp-ts"
            , "Haskell"
            , "Kubernetes"
            , "Nix"
            , "CI/CD"
            ]
      , from = "February 2022"
      , to = "December 2022"
      }
    , { company = "Catawiki"
      , link = "https://catawiki.com"
      , roles = Just [ "Senior Software Engineer" ]
      , description = "helped people to buy and sell special objects by improving the payments and shipping experiences."
      , techs =
            [ "TypeScript"
            , "React"
            , "fp-ts"
            , "Docker"
            , "Kubernetes"
            , "CI/CD"
            ]
      , from = "October 2019"
      , to = "January 2022"
      }
    , { company = "HousingAnywhere"
      , link = "https://housinganywhere.com"
      , roles = Just [ "Senior Software Engineer", "Team Lead" ]
      , description = "I helped to change the way people, specially students, find accommodation around the world.."
      , techs =
            [ "TypeScript"
            , "React"
            , "Node.js"
            , "Golang"
            , "Docker"
            , "Kubernetes"
            , "CI/CD"
            ]
      , from = "May 2017"
      , to = "September 2019"
      }
    , { company = "Altoros"
      , link = "http://www.altoroslabs.com/"
      , roles = Nothing
      , description = "Worked with really smart and cool people developing awesomely challenging applications and APIs."
      , techs =
            [ "JavaScript"
            , "Node.js"
            , "React"
            , "Angular"
            ]
      , from = "April 2016"
      , to = "May 2017"
      }
    , { company = "4r Soluciones"
      , link = "http://www.4rsoluciones.com/"
      , roles = Nothing
      , description = "Worked developing visually appealing marketing sites and customized content management systems and applications."
      , techs =
            [ "PHP"
            , "WordPress"
            , "JavaScript"
            , "Angular"
            ]
      , from = "July 2015"
      , to = "March 2016"
      }
    ]
