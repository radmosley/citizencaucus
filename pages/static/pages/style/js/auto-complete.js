//get search input
$('#search').keyup(function(){
    let value = $('#searchbox').val()
    if (value.length > 0){
        $.ajax({
            type: "POST",
            url: "/search/",
            data: {
                'search_text' : value,
            },
            success: function(response){
            $("#search-results").html(response.html)
            },
            error: function () {
                console.log('error on ajax.')
            }
        });


    }
});

$(document).ready(function(event){
    //open dropdown on search bar focus
        $("#search").focus(function(){
            $("#search-results").show();
        })
    });
    
    //close dropdown on click of window other than the search bar or search results and clear input
    $(window).click(function(event){
        if ($("#search > input[type=text]").length > 0){
            $("#searchbox").val('');
            $("#search-results").hide();
    
        }
    });
    
