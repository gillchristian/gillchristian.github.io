module Pages.Home_ exposing (page)

import Html
import View exposing (View)
import Html.Attributes as Attr
import Components.Social exposing (social)
import Components.Header exposing (header, Page(..))


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
