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

$('#search').click(function(event){
    event.stopPropagation();
    $('#search-results').show();
});

$(document).click(function(){
    $('#search-results').hide();
});