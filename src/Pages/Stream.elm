module Pages.Stream exposing (page)

import Components.Sidebar
import Components.Header exposing (Page(..))
import Html exposing (Html)
import View exposing (View)


page : View msg
page =
  Components.Sidebar.view
    Stream
    { page =
        { title = "Pages.Stream"
        , body = [ Html.text "/stream" ]
        }
    }
