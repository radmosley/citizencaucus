//get search input
$('#search').keyup(function(){
    $.ajax({
        type: "POST",
        url: "/search/",
        data: {
            'search_text' : $('#searchbox').val(),
        },
        success: function(response){
        $("#search-results").html(response.html)
        },
        error: function () {
            console.log('error on ajax.')
        }
    });
});

$(document).ready(function(){
//open dropdown on search bar focus
    $("#searchbox").focus(function(){
        $('#search-results').show();
    }).click(function(){
        event.stopPropagation();
});

//close dropdown on click of window other than the search bar or search results and clear input
$(window).click(function(){
    if ($("#search > input[type=text]").length > 0){
        $("#searchbox").val('');
        $("#search-results").hide();

    } else {
        $("#search-results").hide();
        event.stopPropagation();
    }
});

});
