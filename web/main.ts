const img = document.getElementById('frame') as HTMLImageElement;
const stats = document.getElementById('stats') as HTMLElement;

// Use a sample image exported from the Android run.
img.src = './processed_sample.png';
stats.innerText = 'FPS: 12 | Resolution: 640x480';
