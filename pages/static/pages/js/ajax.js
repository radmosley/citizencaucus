
    $('#search').keyup(function(){
        $.ajax({
            type: "POST",
            url: "/search/",
            data: {
                'search_text' : $('#search').val(),
            },
            success: function(response){
            $("#search-results").html(response.html)
            },
            error: function () {
                console.log('error on ajax.')
            }
        });
    });

    // $(function() {
    //     var searchForm = document.getElementById('search-results'),
    //         textInput = searchForm.q,
    //         clearBtn = textInput.nextSibling;
    //     textInput.onkeyup = function() {
    //         // Show the clear button if text input value is not empty
    //         clearBtn.style.visibility = (this.value.length) ? "visible" : "hidden";
    //     };
    //     // Hide the clear button on click, and reset the input value
    //     clearBtn.onclick = function() {
    //         this.style.visibility = "hidden";
    //         textInput.value = "";
    //     };
    // })();