<template>
    <div id="sidebar">
        <ul id="sidebar-menu">
            <li>by state</li>
            <li>by party</li>
            <li>current</li>
            <li>present</li>
        </ul>
    </div>
</template>

<style scoped>
#sidebar {
    height: 100vh;
    background-color: grey;
    width: 25em;
    display: -webkit-box;
    display: -ms-flexbox;
    display: flex;
    color: white;
}
ul {
    margin: 20px auto;
    list-style: none;
}

li {
    list-style: none;
}

a {
    text-decoration: none;
}

</style>