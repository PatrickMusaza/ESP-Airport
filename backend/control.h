const char PAGE_CONTROL[] PROGMEM = R"=====(


<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Control - Airport of Ethiopia – Airport de Ethiopia</title>
    <link
      rel="icon"
      href="assets/cropped-LOGOS_LOGO-Aeroportos_de-Mocambique-192x192.png"
      type="image/png"
    />
    <style>
      /* General Styles */
      body {
        margin: 0;
        font-family: "MetricHPE", "Trebuchet MS", "Lucida Sans Unicode",
          "Lucida Grande", "Lucida Sans", Arial, sans-serif;
        background: linear-gradient(15deg, rgb(2, 21, 67), #0a192f);
      }

      /* Navigation Bar */
      #navbar {
        position: fixed;
        top: 0;
        left: 0;
        width: 100%;
        padding: 10px 20px;
        display: flex;
        justify-content: center;
        align-items: center;
        z-index: 1000;
        transition: background 0.3s ease;
      }

      .nav-container {
        display: flex;
        justify-content: space-between;
        align-items: center;
        width: 100%;
        max-width: 1200px;
      }

      .nav-logo-1 {
        width: 300px;
        height: 80px;
      }

      .nav-logo-2 {
        width: 150px;
        height: 80px;
      }

      .nav-links {
        display: flex;
        gap: 40px;
        font-size: 2em;
        text-transform: uppercase;
        list-style: none;
        margin: 0;
        padding: 0;
      }

      .nav-links a {
        text-decoration: none;
        color: #ffffff;
        font-weight: bold;
        transition: color 0.3s ease;
      }

      .nav-links a:hover {
        color: #0624b6;
      }

      /* Hamburger Menu */
      .hamburger {
        display: none;
        flex-direction: column;
        cursor: pointer;
        margin-right: 30px;
      }

      .hamburger span {
        width: 50px;
        height: 4px;
        background: #fff;
        margin: 4px 10px;
        transition: 0.3s;
        border-radius: 10px;
      }

      .hamburger.close span:nth-child(1) {
        transform: rotate(45deg) translate(6px, 12px);
      }

      .hamburger.close span:nth-child(2) {
        opacity: 0;
      }

      .hamburger.close span:nth-child(3) {
        transform: rotate(-45deg) translate(6px, -12px);
      }

      /* control */

      h1 {
        color: #fff;
        margin-top: 7%;
        text-align: center;
        font-size: 3rem;
        text-transform: uppercase;
      }

      .content {
        display: flex;
        flex-direction: row;
        gap: 10px;
        padding: 20px;
        justify-content: center;
        bottom: 50px;
        position: relative;
      }

      .preview-area {
        width: 70%;
        border-radius: 10px;
        display: grid;
        grid-template-columns: repeat(2, 1fr);
        grid-template-rows: repeat(2, 1fr);
        gap: 10px;
        padding: 10px;
      }

      .preview-area img {
        width: 100%;
        object-fit: cover;
        border-radius: 10px;
        cursor: pointer;
        transition: transform 0.3s, box-shadow 0.3s;
      }

      .preview-area img:hover {
        transform: scale(1.05);
        box-shadow: 0 8px 12px rgba(0, 0, 0, 0.5);
      }

      .lights-grid {
        width: 30%;
        display: grid;
        grid-template-columns: repeat(minmax(200px, 1fr));
        gap: 20px;
      }

      .light-card {
        background-color: rgba(255, 255, 255, 0.3);
        border-radius: 10px;
        padding: 20px;
        box-shadow: 0 4px 6px rgba(0, 0, 0, 0.3);
        display: flex;
        flex-direction: column;
        align-items: flex-start;
        gap: 10px;
        cursor: pointer;
        transition: transform 0.3s, box-shadow 0.3s;
        position: relative;
      }

      .light-card:hover {
        transform: translateY(-5px);
        box-shadow: 0 8px 12px rgba(0, 0, 0, 0.5);
      }

      .light-card.active {
        background-color: rgba(255, 255, 255, 0.2);
        box-shadow: 0 8px 12px rgba(0, 0, 0, 0.5);
      }

      .light-icon {
        font-size: 40px;
        color: #fff;
      }

      .light-name {
        font-size: 18px;
        color: #fff;
        margin-bottom: 5px;
      }

      .light-description {
        font-size: 14px;
        color: #ccc;
        margin-bottom: 5px;
      }

      .light-status {
        font-size: 12px;
        color: #28a745;
        display: flex;
        align-items: center;
        gap: 5px;
      }

      .light-status::before {
        content: "";
        width: 10px;
        height: 10px;
        background-color: #ccc;
        border-radius: 50%;
        transition: background-color 0.3s;
      }

      .light-card.on .light-status::before {
        background-color: #28a745;
      }

      .light-card.on {
        background-color: rgba(255, 255, 255, 0.2);
        box-shadow: 0 8px 12px rgba(0, 0, 0, 0.5);
      }

      .light-card.on .light-icon {
        color: yellow;
        text-shadow: 0 0 50px yellow;
      }

      .power-light {
        width: 60px;
        height: 10px;
        background: linear-gradient(90deg, #ff000096, #b3ff0096);
        border-radius: 5px;
        position: absolute;
        bottom: 10px;
        left: 50%;
        transform: translateX(-50%);
        transition: background 0.3s;
      }

      .light-card.on .power-light {
        background: linear-gradient(90deg, #00ff0096, #32cd3296);
      }

      .switch {
        position: absolute;
        right: 20px;
        top: 50%;
        transform: translateY(-50%);
      }

      .switch input[type="checkbox"] {
        width: 40px;
        height: 20px;
        appearance: none;
        background-color: rgba(255, 213, 0, 0.7);
        border-radius: 10px;
        position: relative;
        cursor: pointer;
        transition: background-color 0.3s;
      }

      .switch input[type="checkbox"]:checked {
        background-color: #28a745;
      }

      .switch input[type="checkbox"]::before {
        content: "";
        width: 18px;
        height: 18px;
        background-color: #ddff00;
        border-radius: 50%;
        position: absolute;
        top: 1px;
        left: 1px;
        transition: transform 0.3s;
      }

      .switch input[type="checkbox"]:checked::before {
        transform: translateX(20px);
      }

      .control-button {
        margin: 20px;
        padding: 10px 20px;
        font-size: 16px;
        background-color: #28a745;
        color: #fff;
        border: none;
        border-radius: 5px;
        cursor: pointer;
      }

      .control-button:hover {
        background-color: #218838;
      }

      /* Footer Styles */

      footer {
        position: fixed;
        bottom: 0;
        left: 0;
        width: 100%;
        background-color: rgba(0, 0, 0, 0.7);
        color: #fff;
        text-align: center;
        padding: 10px 0;
        font-size: 1.2em;
        font-weight: 400;
      }

      footer a {
        color: #073e91;
        text-decoration: none;
        transition: color 0.3s ease;
      }

      footer a:hover {
        color: #fff;
      }

      /* Responsive Styles */
      @media (max-width: 768px) {
        h1 {
          margin-top: 50px;
          margin-bottom: 50px;
          font-size: 1rem;
        }

        .nav-links {
          display: none;
          flex-direction: column;
          position: absolute;
          top: 80px;
          left: 0;
          width: 100%;
          height: calc(100vh - 100px);
          border-radius: 30px 30px 0 0;
          background: rgba(77, 178, 245, 0.9);
          text-align: center;
        }

        .nav-links.active {
          display: flex;
        }

        .hamburger {
          display: flex;
        }

        .nav-logo-1,
        .nav-logo-2 {
          width: 80px;
          height: 40px;
        }

        .content {
          flex-direction: row;
          align-items: center;
          padding: 10px;
          bottom: 0;
          width: 90%;
        }

        .preview-area {
          width: 100%;
          display: block;
          margin-bottom: 20px;
        }

        .lights-grid {
          width: 70%;
          display: grid;
          grid-template-columns: 1fr;
          gap: 10px;
        }

        .light-card {
          width: 100%;
          padding: 15px;
        }

        .light-icon {
          font-size: 30px;
        }

        .light-name {
          font-size: 16px;
        }

        .light-description {
          font-size: 12px;
        }

        .light-status {
          font-size: 10px;
        }

        .switch input[type="checkbox"] {
          width: 35px;
          height: 18px;
        }

        .switch input[type="checkbox"]::before {
          width: 15px;
          height: 15px;
        }

        .power-light {
          width: 50px;
          height: 3px;
        }

        .control-button {
          font-size: 14px;
          padding: 8px 16px;
        }

        footer {
          margin-top: 10vh;
          font-size: 0.64em;
        }
      }
    </style>
  </head>

  <body>
    <!-- Navigation Bar -->
    <nav id="navbar">
      <div class="nav-container">
        <img
          src="assets/cropped-Animated-Logo-500x500-px-5-removebg-preview.png"
          alt="Logo 1"
          class="nav-logo-1"
        />
        <ul class="nav-links">
          <li><a href="/">Home</a></li>
          <li><a href="/control">Control</a></li>
          <li><a href="/gallery">Gallery</a></li>
        </ul>
        <div class="hamburger" id="hamburger">
          <span></span>
          <span></span>
          <span></span>
        </div>
      </div>
    </nav>

    <h1>Airport Control Panel</h1>
    <div class="content">
      <!-- Part 1: Preview Area -->
      <div class="preview-area">
        <img
          src="https://picsum.photos/800/600?random=1"
          alt="Preview 1"
          onclick="expandPreview(1)"
        />
        <img
          src="https://picsum.photos/800/600?random=2"
          alt="Preview 2"
          onclick="expandPreview(2)"
        />
        <img
          src="https://picsum.photos/800/600?random=3"
          alt="Preview 3"
          onclick="expandPreview(3)"
        />
        <img
          src="https://picsum.photos/800/600?random=4"
          alt="Preview 4"
          onclick="expandPreview(4)"
        />
        <img
          src="https://picsum.photos/800/600?random=5"
          alt="Preview 5"
          onclick="expandPreview(5)"
        />
        <img
          src="https://picsum.photos/800/600?random=6"
          alt="Preview 6"
          onclick="expandPreview(6)"
        />
        <img
          src="https://picsum.photos/800/600?random=7"
          alt="Preview 7"
          onclick="expandPreview(7)"
        />
        <img
          src="https://picsum.photos/800/600?random=8"
          alt="Preview 8"
          onclick="expandPreview(8)"
        />
      </div>

      <!-- Part 2: Lights Grid -->
      <div class="lights-grid">
        <div class="light-card" id="light-card-1" onclick="expandPreview(1)">
          <div class="light-icon">💡</div>
          <div class="light-name">Light 1</div>
          <div class="light-description">Runway Light</div>
          <div class="light-status">Status: Off</div>
          <div class="power-light"></div>
          <div class="switch">
            <input type="checkbox" id="switch1" onchange="toggleLight(1)" />
          </div>
        </div>
        <div class="light-card" id="light-card-2" onclick="expandPreview(2)">
          <div class="light-icon">💡</div>
          <div class="light-name">Light 2</div>
          <div class="light-description">Taxiway Light</div>
          <div class="light-status">Status: Off</div>
          <div class="power-light"></div>
          <div class="switch">
            <input type="checkbox" id="switch2" onchange="toggleLight(2)" />
          </div>
        </div>
        <div class="light-card" id="light-card-3" onclick="expandPreview(3)">
          <div class="light-icon">💡</div>
          <div class="light-name">Light 3</div>
          <div class="light-description">Apron Light</div>
          <div class="light-status">Status: Off</div>
          <div class="power-light"></div>
          <div class="switch">
            <input type="checkbox" id="switch3" onchange="toggleLight(3)" />
          </div>
        </div>
        <div class="light-card" id="light-card-4" onclick="expandPreview(4)">
          <div class="light-icon">💡</div>
          <div class="light-name">Light 4</div>
          <div class="light-description">Terminal Light</div>
          <div class="light-status">Status: Off</div>
          <div class="power-light"></div>
          <div class="switch">
            <input type="checkbox" id="switch4" onchange="toggleLight(4)" />
          </div>
        </div>
        <div class="light-card" id="light-card-5" onclick="expandPreview(5)">
          <div class="light-icon">💡</div>
          <div class="light-name">Light 5</div>
          <div class="light-description">Hangar Light</div>
          <div class="light-status">Status: Off</div>
          <div class="power-light"></div>
          <div class="switch">
            <input type="checkbox" id="switch5" onchange="toggleLight(5)" />
          </div>
        </div>
        <div class="light-card" id="light-card-6" onclick="expandPreview(6)">
          <div class="light-icon">💡</div>
          <div class="light-name">Light 6</div>
          <div class="light-description">Control Tower Light</div>
          <div class="light-status">Status: Off</div>
          <div class="power-light"></div>
          <div class="switch">
            <input type="checkbox" id="switch6" onchange="toggleLight(6)" />
          </div>
        </div>
        <div class="light-card" id="light-card-7" onclick="expandPreview(7)">
          <div class="light-icon">💡</div>
          <div class="light-name">Light 7</div>
          <div class="light-description">Parking Light</div>
          <div class="light-status">Status: Off</div>
          <div class="power-light"></div>
          <div class="switch">
            <input type="checkbox" id="switch7" onchange="toggleLight(7)" />
          </div>
        </div>
        <div class="light-card" id="light-card-8" onclick="expandPreview(8)">
          <div class="light-icon">💡</div>
          <div class="light-name">Light 8</div>
          <div class="light-description">Emergency Light</div>
          <div class="light-status">Status: Off</div>
          <div class="power-light"></div>
          <div class="switch">
            <input type="checkbox" id="switch8" onchange="toggleLight(8)" />
          </div>
        </div>
      </div>
    </div>
    <!-- Footer Section -->

    <footer>
      &copy; 2025 Airport Control Panel | Developed & Powered by
      <a href="https://tech.happylight.rw/">Happy Light Tech Ltd</a> | All
      rights reserved.
    </footer>

    <script>
      // Navigation Bar Scroll Effect
      window.addEventListener("scroll", function () {
        const navbar = document.getElementById("navbar");
        const navLinks = document.querySelectorAll(".nav-links a");
        const hamburgerSpans = document.querySelectorAll(".hamburger span"); // Correcting this

        if (window.scrollY > 50) {
          navbar.style.background = "#fff";
          hamburgerSpans.forEach((span) => (span.style.background = "#000")); // Apply background to each span
          navLinks.forEach((link) => (link.style.color = "#000"));

          addLinkHoverEffect(navLinks, "#1925B0FF", "#000");
        } else {
          navbar.style.background = "transparent";
          hamburgerSpans.forEach((span) => (span.style.background = "#fff")); // Apply background to each span
          navLinks.forEach((link) => (link.style.color = "#fff"));

          addLinkHoverEffect(navLinks, "#1925B0FF", "#fff");
        }
      });

      // Helper function to avoid duplicated code for hover effect
      function addLinkHoverEffect(navLinks, hoverColor, originalColor) {
        navLinks.forEach((link) => {
          link.addEventListener("mouseover", () => {
            link.style.color = hoverColor; // Color on hover
          });

          link.addEventListener("mouseout", () => {
            link.style.color = originalColor; // Color when hover ends
          });
        });
      }

      // Hamburger Menu Toggle
      const hamburger = document.getElementById("hamburger");
      const navLinks = document.querySelector(".nav-links");

      hamburger.addEventListener("click", function () {
        navLinks.classList.toggle("active");
        hamburger.classList.toggle("close");
      });

      function toggleLight(lightNumber) {
        const lightCard = document.getElementById(`light-card-${lightNumber}`);
        const switchInput = document.getElementById(`switch${lightNumber}`);
        const status = lightCard.querySelector(".light-status");

        const isOn = switchInput.checked;
        const state = isOn ? "on" : "off";

        fetch(`/control?device=relay${lightNumber}&state=${state}`)
          .then((response) => {
            if (response.ok) {
              lightCard.classList.toggle("on", isOn);
              status.textContent = `Status: ${isOn ? "On" : "Off"}`;
              switchInput.checked = isOn;
            } else {
              console.error("Failed to toggle relay");
              switchInput.checked = !isOn;
            }
          })
          .catch((error) => {
            console.error("Error:", error);
            switchInput.checked = !isOn;
          });
      }

      function expandPreview(lightNumber) {
        const previewArea = document.querySelector(".preview-area");
        const previewImages = document.querySelectorAll(".preview-area img");

        previewImages.forEach((img) => {
          img.style.gridColumn = "";
          img.style.gridRow = "";
          img.style.height = "";
        });

        const clickedImage = previewImages[lightNumber - 1];
        clickedImage.style.gridColumn = "1/3";
        clickedImage.style.gridRow = "1/3";
        clickedImage.style.height = "100vh";

        previewImages.forEach((img, index) => {
          if (index + 1 !== lightNumber) {
            img.style.height = "30vh";
          }
        });
      }
    </script>
  </body>
</html>


)=====";