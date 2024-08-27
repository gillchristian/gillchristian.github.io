module Components.Header exposing (Page(..), header)

import Html exposing (Html)
import Html.Attributes as Attr


type Page
    = Home
    | Stream
    | Articles
    | Projects
    | Talks
    | About


header : Page -> Html msg
header current =
    Html.div
        [ Attr.class "header" ]
        [ link Articles current "/articles" "Writing"
        , link Projects current "/projects" "Projects"
        , link Talks current "/talks" "Talks"
        , link About current "/about" "About"
        ]


link : Page -> Page -> String -> String -> Html msg
link page current href label =
    if page == current then
        Html.span
            [ Attr.class "header-active"
            ]
            [ Html.text label ]

    else
        Html.a
            [ Attr.class "header-link"
            , Attr.href href
            ]
            [ Html.text label ]
