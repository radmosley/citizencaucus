<template>
<!--Navbar-->
<div class="navbar">
        <div class="container">
                <h1><a href="#" class="home">{{ title }}</a></h1>
                        <div class="searchwrapper">
                                <form id="search" accept-charset="utf-8">
                                        <div class="searchbox">
                                                <div class="button">
                                                        <i class="fas fa-search"></i>
                                                </div>
                                                <div class="placeholder-text">
                                                        <input class="searchTerm" id="searchbox" name="q" type="text" placeholder="search" autocomplete="off">
                                                </div>
                                        </div>
                                </form>
                        </div>
        </div>  
</div>
</template>

<script>
export default {
        data: function (){
                return {
                        title: "Citizen Caucus".toUpperCase()
    }
        }
}
</script>


<style>
.container {
    display: flex;
    flex-direction: row;
    width: 80%;
    margin: 0 auto;
    justify-content: space-between;
}

.navbar {
        background-color: #135575;
        width: 100%;
        top: 0;
        -webkit-box-shadow: -1px -6px 15px 2px;
        box-shadow: -1px -6px 15px 2px;
        border-bottom-color: #FFC400;
        border-bottom-style: solid;
        border-bottom-width: 5px;
}


.home {
    color: white;
    text-decoration: none;
    margin: auto 0
}

.searchwrapper {
        margin: auto 0;
        width: 30%;
        height: 5vh;
}

#search {
        background: white;
}

input#searchbox{
        height: 100%;
        width: 100%;
}

</style>
