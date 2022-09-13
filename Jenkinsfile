pipeline{

    agent {
        label 'master'
    }

    options {
        disableConcurrentBuilds()
    }

    environment {
        discordWebHookUrl = credentials('efbc440a-0d19-4ca1-b9fa-5db6a8112071')
        discordImg = 'https://cdn.discordapp.com/attachments/677086996182859786/884703330734063656/mifu-cube.png'
        FILE_NAME="Lexicon"
        SITE_LOCATION="/var/www/mythotic.com/lexicon/builds/lexicon_main"
    }
    
    stages{
        stage("Build on Branch") {
            when {
                branch "dev"
            }
            steps {
                echo "=========Building PK3 File has started========="
                discordSend(
                    webhookURL: discordWebHookUrl, 
                    title: 'Creation Magic has been invoked!',
                    link: env.BUILD_URL,
                    description: 'Lexicon Main File Build ' + env.BUILD_ID  + " on " + env.BRANCH_Name, 
                    footer: 'Lexicon Automata Cube',
                    customUsername: "Afina's Lexicon Creation Cube",
                    customAvatarUrl: discordImg,
                    showChangeset: true,
                    thumbnail: discordImg
                )
                sh 'chmod +x ./automata.sh && ./automata.sh'
                echo "=========Building PK3 Complete========="
                sh 'whoami'
            }
        }
        stage("Build on Tag") {
            when {
                buildingTag()
            }
            steps {
                echo "=========Building PK3 File has started========="
                discordSend(
                    webhookURL: discordWebHookUrl, 
                    title: 'Creation Magic has been invoked!',
                    link: env.BUILD_URL,
                    description: 'Lexicon Mail File Build ' + env.BUILD_ID  + " on " + env.TAG_NAME + '\n' + 'Oh shit, a new release?!', 
                    footer: 'Lexicon Automata Cube',
                    customUsername: "Afina's Lexicon Creation Cube",
                    customAvatarUrl: discordImg,
                    showChangeset: true,
                    thumbnail: discordImg
                )
                sh 'chmod +x ./automata.sh && ./automata.sh'
                echo "=========Building PK3 Complete========="
            }
        }
        stage("Rename Branch PK3 File") {
            when {
                branch "dev"
            }
            steps {
                echo "=========Renaming PK3 File to ${FILE_NAME}_${BRANCH_NAME}_${BUILD_NUMBER}.pk3========="
                sh "mv -v ./${FILE_NAME}.pk3 ./${FILE_NAME}_${BRANCH_NAME}_${BUILD_NUMBER}.pk3"
                echo "=========Renaming Complete========="
                script {
                    FULL_FILENAME = "${FILE_NAME}_${BRANCH_NAME}_${BUILD_NUMBER}.pk3"
                }
            }
        }
        stage("Rename Release PK3 File") {
            when {
                buildingTag()
            }
            steps {
                echo "=========Renaming PK3 File to ${FILE_NAME}_${TAG_NAME}.pk3========="
                sh "mv -v ./${FILE_NAME}.pk3 ./${FILE_NAME}_${TAG_NAME}.pk3"
                echo "=========Renaming Complete========="
                script {
                    FULL_FILENAME = "${FILE_NAME}_${TAG_NAME}.pk3"
                }
            }
        }
        stage("Deploy Dev File to Web Server Dev Folder") {
            when {
                branch "dev"
            }
            steps {
                echo "=========Copying ${FULL_FILENAME} to dev build folder website========="
                sh "cp -v ./${FULL_FILENAME} ${SITE_LOCATION}/dev"
                echo "=========Copying Complete========="
                echo "=========Saving Artifacts========="
                archiveArtifacts artifacts: FULL_FILENAME, followSymlinks: false, onlyIfSuccessful: true
                
            }
        }
        stage("Deploy Release to Web Server Stable Folder") {
            when {
                buildingTag()
            }
            steps {
                echo "=========Copying ${FULL_FILENAME} to stable build folder website========="
                sh "cp -v ./${FULL_FILENAME} ${SITE_LOCATION}/stable"
                echo "=========Copying Complete========="
                echo "=========Saving Artifacts========="
                archiveArtifacts artifacts: FULL_FILENAME, followSymlinks: false, onlyIfSuccessful: true
            }
        }
    }
    post{
        success{
            echo "========Pipeline Successful. Executing Post Mortem Actions========"
            echo "========Sending Success Discord Notif========"
            discordSend(
                    webhookURL: discordWebHookUrl, 
                    title: 'Creation Complete!',
                    link: env.BUILD_URL, 
                    description: 'Lexicon Mail File Build Complete with filename ' + FULL_FILENAME, 
                    footer: 'Lexicon Automata Cube',
                    customUsername: "Afina's Lexicon Creation Cube",
                    customAvatarUrl: discordImg,
                    showChangeset: true,
                    thumbnail: discordImg,
                    result: 'SUCCESS'
                )

        }
        failure{
            echo "========Pipeline Failed. Executing Really Really Post Mortem Actions========"
            discordSend(
                    webhookURL: discordWebHookUrl, 
                    title: 'Afina ran out of Mana!',
                    link: env.BUILD_URL, 
                    description: 'Lexicon Main File Build failed with filename ' + FULL_FILENAME + '. Please check the jobs logs to determine failure', 
                    footer: 'Lexicon Automata Cube',
                    customUsername: "Afina's Lexicon Creation Cube",
                    customAvatarUrl: discordImg,
                    showChangeset: true,
                    thumbnail: discordImg,
                    result: 'FAILURE'
                )
        }
    }
}