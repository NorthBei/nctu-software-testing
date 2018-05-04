pipeline {
    agent {
        docker {
            image 'gcc'
        }
    }
    stages {
        stage('Build') {
            steps {
                sh 'make -C ./hw1/Triangle'
                sh 'make -C ./hw1/NextDate'
                sh 'make -C ./hw1/CommissionProblem'
            }
        }
        stage('Test') {
            steps {
                sh 'make -C ./hw1/Triangle test'
                sh 'make -C ./hw1/NextDate test'
                sh 'make -C ./hw1/CommissionProblem test'
            }
        }
    }
}