#include <iostream>
#include <curl/curl.h>
#include <ctime>
#include <thread>
#include <chrono>

const char* smtp_server = "smtp://smtp.example.com:587"; // Replace with your SMTP server
const char* username = "your_email@example.com"; // Replace with your email
const char* password = "your_password"; // Replace with your email password

void send_email(const std::string& to, const std::string& from, const std::string& subject, const std::string& body) {
    CURL* curl;
    CURLcode res = CURLE_OK;
    struct curl_slist* recipients = nullptr;
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_USERNAME, username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password);
        curl_easy_setopt(curl, CURLOPT_URL, smtp_server);

        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from.c_str());

        recipients = curl_slist_append(recipients, to.c_str());
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);

        std::string payload_text = "To: " + to + "\r\n" + 
                                   "From: " + from + "\r\n" +
                                   "Subject: " + subject + "\r\n" +
                                   "\r\n" + 
                                   body + "\r\n";

        curl_easy_setopt(curl, CURLOPT_READFUNCTION, nullptr);
        curl_easy_setopt(curl, CURLOPT_READDATA, &payload_text);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }
}

void daily_email_task() {
    while (true) {
        std::time_t now = std::time(nullptr);
        std::tm* now_tm = std::localtime(&now);
        
        // Set the time for 8:00 AM
        now_tm->tm_hour = 8;
        now_tm->tm_min = 0;
        now_tm->tm_sec = 0;
        
        std::time_t next_time = std::mktime(now_tm);
        
        if (next_time < now) {
            next_time += 24 * 60 * 60; // Add one day
        }

        std::this_thread::sleep_until(std::chrono::system_clock::from_time_t(next_time));

        send_email("recipient@example.com", "your_email@example.com", "Daily Report", "This is the daily report.");
    }
}

int main() {
    std::thread email_thread(daily_email_task);
    email_thread.detach(); // Detach the thread so it runs independently

    // Keep the main thread alive
    while (true) {
        std::this_thread::sleep_for(std::chrono::hours(24));
    }

    return 0;
}
