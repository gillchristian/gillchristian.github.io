module Pages.Home_ exposing (page)

import Components.Header exposing (Page(..), header)
import Components.Social exposing (social)
import Html
import Html.Attributes as Attr
import View exposing (View)


page : View msg
page =
    { title = "Home"
    , body =
        [ Html.div
            [ Attr.class "home-wrapper" ]
            [ Html.div
                [ Attr.class "home-logo" ]
                [ Html.div [ Attr.class "home-avatar" ] []
                , Html.h1 [ Attr.class "home-title" ] [ Html.text "Christian Gill" ]
                ]
            , Html.div
                [ Attr.class "home-header" ]
                [ header Home ]
            , social
            ]
        ]
    }
