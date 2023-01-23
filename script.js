const navContent = `
    <li><a href="#">Resume</a></li>
    <li><a href="#">More About Me</a></li>
    <li><a href="#">Hobbies</a></li>
    <li><a href="#">Other</a></li>
`

const mainNav = document.createElement("nav");
mainNav.classList.add("main-navigation");
const navList = document.createElement("ul");
navList.innerHTML = navContent;
mainNav.append(navList);

document.querySelector(".siteheader").append(mainNav); 