const char PAGE_GALLERY[] PROGMEM = R"=====(
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Gallery - Projects & Experience</title>
        <style>
            body {
                margin: 0;
                font-family: Arial, sans-serif;
                background-color: #f4f4f4;
                color: #333;
            }
            header {
                text-align: center;
                padding: 20px;
                background-color: #0425c9;
                color: #fff;
            }
            h1 {
                margin: 0;
                font-size: 2.5rem;
            }
            .gallery {
                display: grid;
                grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
                gap: 15px;
                padding: 20px;
            }
            .gallery-item {
                position: relative;
                overflow: hidden;
                border-radius: 10px;
                box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);
                transition: transform 0.3s ease, box-shadow 0.3s ease;
            }
            .gallery-item img {
                width: 100%;
                height: 100%;
                object-fit: cover;
                transition: transform 0.3s ease;
            }
            .overlay {
                position: absolute;
                top: 0;
                left: 0;
                width: 100%;
                height: 100%;
                background: rgba(0, 0, 0, 0.5);
                display: flex;
                justify-content: center;
                align-items: center;
                opacity: 0;
                transition: opacity 0.3s ease;
            }
            .text {
                color: #fff;
                font-size: 1.5rem;
                text-align: center;
                transform: translateY(20px);
                transition: transform 0.3s ease;
            }
            .gallery-item:hover {
                transform: scale(1.05);
                box-shadow: 0 8px 16px rgba(0, 0, 0, 0.3);
            }
            .gallery-item:hover img {
                transform: scale(1.1);
            }
            .gallery-item:hover .overlay {
                opacity: 1;
            }
            .gallery-item:hover .text {
                transform: translateY(0);
            }
        </style>
    </head>
    <body>
        <header>
            <h1>Gallery - Projects & Experience</h1>
        </header>
    
        <div class="gallery">
            <!-- Dynamically load images from SD card -->
            <div class="gallery-item">
                <img src="/image?path=/image1.jpg" alt="Project 1">
                <div class="overlay">
                    <div class="text">Project 1</div>
                </div>
            </div>
            <div class="gallery-item">
                <img src="/image?path=/image2.jpg" alt="Project 2">
                <div class="overlay">
                    <div class="text">Project 2</div>
                </div>
            </div>
            <!-- Add more images as needed -->
        </div>
    
        <footer>
            &copy; 2025 Gallery | Powered by HappyLight Tech
        </footer>
    </body>
    </html>
    )=====";