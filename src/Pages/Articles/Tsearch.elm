module Pages.Articles.Tsearch exposing (page)

import Components.Header exposing (Page(..))
import Components.Sidebar
import Html exposing (Html)
import View exposing (View)


page : View msg
page =
    Components.Sidebar.view
        Articles
        { page =
            { title = "Pages.Articles.Tsearch"
            , body = [ Html.text "/articles/tsearch" ]
            }
        }
