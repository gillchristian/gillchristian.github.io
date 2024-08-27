module Components.Social exposing (social)

import Html exposing (Html)
import Html.Attributes as Attr


social : Html msg
social =
    Html.div
        []
        [ Html.a
            [ Attr.class "social-link"
            , Attr.href "https://twitter.com/gillchristian"
            , Attr.target "_blank"
            , Attr.rel "noopener noreferrer"
            ]
            [ Html.text "Twitter" ]
        , Html.a
            [ Attr.class "social-link"
            , Attr.href "https://github.com/gillchristian"
            , Attr.target "_blank"
            , Attr.rel "noopener noreferrer"
            ]
            [ Html.text "GitHub" ]
        , Html.a
            [ Attr.class "social-link"
            , Attr.href "https://www.linkedin.com/in/gillchristian/"
            , Attr.target "_blank"
            , Attr.rel "noopener noreferrer"
            ]
            [ Html.text "LinkedId" ]
        ]
