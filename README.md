# Temeo Video App Prototype (MVP)

Welcome to the Temeo Video App Prototype! This project is a collaborative effort, and each team member has made significant contributions to different aspects of the development process.

## Table of Contents
- [Getting Started](#getting-started)
- [Features](#features)
- [Version History](#version-history)
- [Contributions](#contributions)
- [Frequently Asked Questions (FAQ)](#frequently-asked-questions-faq)
- [Contact Information](#contact-information)
- [License](#license)

## Getting Started

### Installation

1. Clone the project repository:

   ```bash
   git clone git@github.com:2023Leeds-UI-G5/Temeo.git
   ```

2. Navigate to the project directory:

   ```bash
   cd Temeo
   ```

3. Generate the makefile using qmake (from QT Creator 5.15.2):

   ```bash
   qmake Temeo.pro
   ```

4. Build the project using make:

   ```bash
   make
   ```

   Alternatively, open the project in QT Creator and run it from there.

### Running the App

- If using make, run the following command:

  ```bash
  ./Temeo
  ```

- If using QT Creator, open the project in QT Creator and click the "Run" button.

## Features

1. **Basic Control Features:**
   - Implemented play, pause, progress bar, and volume control.
   - Added fast playback, fast forward/backward, and full-screen playback functionalities.
   - Introduced shortcuts for enhanced user control.

2. **Playlist-related Features:**
   - Established a video playlist linked to the "videos" folder.
   - Enabled video playback initiation through a simple click on icons within the playlist.
   - Introduced a search function for the playlist.
   - Implemented the option to freely select a video folder as the video playback playlist.

3. **Additional Enhancements:**
   - Implemented a video screenshot feature.
   - Language Switching: implemented a language-switching feature supporting both Chinese and English.
   - Added Day/Night Mode functionality.
   - Optimized the UI layout for responsiveness.

## Version History

### V1.0 (2023.12.9):

- Implemented fundamental player functionalities: play, pause, progress bar, and volume control.
- Established a video playlist linked to the "videos" folder within the same directory.
- Enabled video playback initiation through a simple click on icons within the video playlist.

### V2.0 (2023.12.14):

- Added fast playback, fast forward/back, and full-screen playback functionalities.
- Introduced shortcuts for enhanced user control: single-click to pause, double-click for full-screen, and directional keys for adjusting progress and volume.

### V3.0 (2023.12.20):

#### Optimizations:

- Adjusted the interface layout for improved aesthetics.
- Increased icon diversity to enhance visual appeal.
- Added interfaces to accommodate upcoming functionalities.

#### New Features:

- Implemented a video screenshot feature, enabling users to selectively save screenshots in a designated folder.
- Introduced a search function for the playlist, allowing full-field matching to filter and locate desired videos within the video files.
- Language Switching: implemented a language-switching feature supporting both Chinese and English. The functionality reads the host's location for language initialization, allowing users to freely switch between languages after the initial setup.

#### Bug Fixes:

- Resolved an issue causing display errors in Fullscreen mode after video playback completion.
- Fixed the problem where newly added components continued to display even in Fullscreen mode.

### V4.0 (2023.12.26):

#### Feature Additions:

- Added Day/Night Mode functionality.
- Implemented the option to freely select a video folder as the video playback playlist.

#### Optimizations:

- Adjusted the stylesheet for the UI interface to enhance the aesthetics of Day/Night Mode.
- Added hover mode to buttons for improved user interaction.
- Optimized the UI layout to make it responsive to window size changes.

#### Bug Fixes:

- Resolved an issue causing display errors in Fullscreen mode after video playback completion.
- Fixed the problem where newly added components continued to display even in Fullscreen mode.

## Contributions

Our team members have played crucial roles in the development of this project:

### 1. Jingwei Zhang (UI Design and Adaptation)

   - **UI Design:**
     - Formulated an overall UI design plan for the project, including themes, colors, and icons.
     - Designed and illustrated specific styles and layouts for each interface.
     - Ensured UI consistency for a user-friendly interface.

   - **Adaptation Design:**
     - Ensured the project displays well on various resolutions and devices.
     - Utilized Qt

's adaptive layout tools to guarantee adaptability across different screens.
     - Optimized UI for diverse platforms and devices, such as mobile and desktop.

   - **GitHub:** [Tylor110077](https://github.com/Tylor110077)

### 2. Junyu Zhou (Meeting Documentation, Video Production, Mode Switching, and Report Writing)

   - **Meeting Documentation and Video Production:**
     - Recorded detailed content of each meeting, encompassing discussion topics, decisions, and task assignments.
     - Maintained a meeting documentation file for team members' reference.
     - Recorded proceedings of each iteration and the final iteration.
     - Produced clear, concise project progress videos emphasizing key information.
     - Demonstrated project functionality and interfaces in videos for team and stakeholders' understanding.

   - **Code Implementation for Mode Switching:**
     - Implemented mode switching functionality, including switching between Chinese and English modes and day/night modes.
     - Ensured smooth and user-friendly transition functionality.
     - Collaborated with the UI design team to ensure correct presentation of interface styles after mode switches.

   - **Partial Report Writing for the Final Project Report:**
     - Assisted in drafting relevant sections of the final project report, including project overview, development process, key decisions, technical implementations, and team collaboration.

   - **GitHub:** [CHNdominic](https://github.com/CHNdominic)

### 3. Zhengzi Yang (Testing and Evaluation, Meeting Organization, and Report Writing)

   - **Testing and Evaluation:**
     - Developed detailed testing plans covering unit, integration, and system tests.
     - Executed tests after each iteration to ensure functionality correctness and stability.
     - Documented test results and identified issues.
     - Regularly evaluated overall project performance, proposing potential improvement suggestions.
     - Collaborated with the development team to promptly address issues identified during testing.
     - Provided detailed feedback on project quality and stability.

   - **Meeting Organization and Report Writing:**
     - Organized each meeting to ensure effective communication and collaboration among project members.
     - Assisted in drafting relevant sections of the final project report, covering testing processes, evaluation results, quality assurance, and team collaboration.
     - Provided information related to meeting organization and reporting for inclusion in the report, showcasing overall project progress and testing processes.

   - **GitHub:** [Q-7-x](https://github.com/Q-7-x)

### 4. Sheng Ning (Code Implementation and Version Management)

   - **Code Implementation:**
     - Designed and implemented core functionality modules, ensuring code quality and maintainability.
     - Addressed and debugged project bugs promptly.
     - Collaborated closely with the UI design team to seamlessly integrate interfaces and functionalities.

   - **Version Management:**
     - Employed version control tools (e.g., Git) for code version management.
     - Managed project builds and releases to ensure version correctness and stability.
     - Oversaw branch management and merging to facilitate smooth collaborative development within the team.

   - **GitHub:** [JieY02](https://github.com/JieY02)

Feel free to contact them through GitHub for specific inquiries related to their areas of expertise.

## Frequently Asked Questions (FAQ)

1. **Why does the software show no available video to play when I try to launch it directly?**
   - Before playing a video, click on the button in the upper right corner to Choose your playback directory and the video you want to play. After completing this operation, you will be able to play the desired video.

2. **Why do some buttons in the software have no effect when clicked?**
   - The main functions of this software include playing, pausing, adjusting video volume, changing playback speed, uploading videos, switching interface language, and toggling between day and night modes. Other buttons are decorative and do not perform specific functions.

3. **Why do I encounter license issues when trying to launch the project?**
   - This is due to license verification failure caused by Qt's educational license. To resolve this issue, download the community version of Qt and try registering/logging in with your personal (non-educational) account.

4. **Why does Qt encounter errors during the Qmake process?**
   - If you encounter this issue, check the integrity of the current installation files and ensure that no additional modifications have been made to the files. Follow these steps:
     - Click on the toolbar on the screen and select Maintenance Tool to launch it.
     - Complete license login and verification.
     - Select Add or Remove Components.
     - Check whether it includes all components of Qt Design Studio 4.3.2, Qt 5.15.2, Qt Creator 12.0.1, Qt Creator 12.0.1 CDB Debugger Support, Debugging Tools for Windows (if you are using Windows), Qt Creator 12.0.1 Debug Symbols, Qt Creator 12.0.1 Plugin Development, MinGW 8.1.0 32-bit or MinGW 8.1.0 64-bit, Ninja 1.10.2, OpenSSL 3.0.12 Toolkit.
     - If some components are not installed, check and install them.

5. **Does the software support streaming services like Netflix or YouTube?**
   - No, this software is a local video player and only supports basic local video playback.

6. **Does it support adjusting video quality or resolution?**
   - No, this software only supports playing videos in their original resolution.

7. **What video formats does the software support?**
   - The software supports WMV format on Windows, MP4 format on Mac, and MOC format on Linux.

8. **How does the software handle user data to protect privacy?**
   - All videos are played locally, and the software does not have online functionality. It does not upload or misuse user data.

9. **Can I use different language versions of the software for different regions?**
   - Yes, the software can automatically detect the current geographical location. If in China, the language will be set to Chinese. If the user is outside of China, the interface will be set to English.

10. **If the software encounters issues, how can I contact the corresponding personnel?**
    - **Technical Support Contact:**
      - Email: 1940660815@qq.com, sc21jz2@leeds.ac.uk, Jingwei Zhang, Sheng Ning
      - Address: Xian Road 999, Sichuan, Southwest Jiaotong University.

## Contact Information

If you have specific questions or encounter issues, feel free to reach out to the corresponding personnel:

1. **Jingwei Zhang (UI Design and Adaptation):**
   - GitHub: [Tylor110077](https://github.com/Tylor110077)

2. **Junyu Zhou (Meeting Documentation, Video Production, Mode Switching, and Report Writing):**
   - GitHub: [CHNdominic](https://github.com/CHNdominic)

3. **Zhengzi Yang (Testing and Evaluation, Meeting Organization, and Report Writing):**
   - GitHub: [Q-7-x](https://github.com/Q-7-x)

4. **Sheng Ning (Code Implementation and Version Management):**
   - GitHub: [JieY02](https://github.com/JieY02)

## License

This project is licensed under the [MIT License](LICENSE).

For any questions or feedback, feel free to contact us at sc21sn@leeds.ac.uk.

Enjoy using the Temeo Video App Prototype!
