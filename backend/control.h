const char PAGE_CONTROL[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Control Panel - Airport</title>
    <style>
      body {
        font-family: MetricHPE, sans-serif;
        margin: 0;
        padding: 0;
        background: linear-gradient(15deg, #083a6c, #330270);
        color: #fff;
        display: flex;
        flex-direction: column;
        align-items: center;
        gap: 20px;
        padding: 20px;
        min-height: 100vh;
        position: relative;
      }
      h1 {
        color: #fff;
      }
      .content {
        width: 100%;
        display: flex;
        flex-direction: row;
        gap: 20px;
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
      footer {
        position: fixed;
        bottom: 0;
        left: 0;
        width: 100%;
        background-color: rgba(0, 0, 0, 0.7);
        color: #fff;
        text-align: center;
        padding: 10px 0;
        font-size: 14px;
      }
    </style>
  </head>
  <body>
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
    <button class="control-button" onclick="window.location.href = '/'">
      Home
    </button>
    <footer>
      &copy; 2025 Airport Control Panel | Developed by Happy Light Tech Ltd |
      All rights reserved.
    </footer>
    <script>
      // Function to toggle lights
      function toggleLight(lightNumber) {
        const lightCard = document.getElementById(`light-card-${lightNumber}`);
        const switchInput = document.getElementById(`switch${lightNumber}`);
        const status = lightCard.querySelector(".light-status");

        if (switchInput.checked) {
          lightCard.classList.add("on");
          status.textContent = "Status: On";
        } else {
          lightCard.classList.remove("on");
          status.textContent = "Status: Off";
        }
      }

      // Function to expand preview
      function expandPreview(lightNumber) {
        const previewArea = document.querySelector(".preview-area");
        const previewImages = document.querySelectorAll(".preview-area img");

        // Reset all images to default size
        previewImages.forEach((img) => {
          img.style.gridColumn = "";
          img.style.gridRow = "";
          img.style.height = "";
        });

        // Expand the clicked image to 50vh
        const clickedImage = previewImages[lightNumber - 1];
        clickedImage.style.gridColumn = "1 / 3";
        clickedImage.style.gridRow = "1 / 3";
        clickedImage.style.height = "100vh";

        // Adjust the remaining images to fill the grid
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