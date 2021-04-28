#include<iostream>
#include<string>
#include<vector>

const int MAX_NUM_SOURCES = 100;
const int MAX_NUM_NEWS_ITEM_PER_SOURCE = 1000;
const int MAX_NUM_CATEGORIES = 50;


class Category {
private:
    std::string categoryName;
    Category* parentCategory;

public:
    Category(std::string categoryName) : categoryName(categoryName) {};
    std::string getCategoryName() {
        return categoryName;
    }
};

class Source {
private:
    std::string URL;
    int numNewsItemsOwned = 0;

public:
    Source(std::string URL) : URL(URL) {};

    std::string getSourceURL() {
        return URL;
    }

    void newNewsItemOwned() {
        numNewsItemsOwned++;
    }

    int getNumNewsItemsOwned() {
        return numNewsItemsOwned;
    }
};

class NewsItem {
private:
    std::string title;
    std::string content;
    std::string authorName;
    int counter;
    Source ownerSource;
    Category category;

public:
    NewsItem(std::string title, std::string content, std::string authorName, Category &category, Source& source) : title(title), content(content), \
    authorName(authorName), category(category), ownerSource(source) {};

    Source* getOwnerSource() {
        return &ownerSource;
    }

    std::string getTitle() {
        return title;
    }

    std::string getContent() {
        return content;
    }
};

class WebPage { //responsible for deleting categories / sources / news items !
private:
    std::vector<NewsItem*> newsItems;
    std::vector<Category*> categories;
    std::vector<Source*> sources;

public:
    WebPage() {};

    ~WebPage() {
        for (int i = 0; i < sources.size(); i++) {
            delete sources[i];
        }
        for (int i = 0; i < categories.size(); i++) {
            delete categories[i];
        }
        for (int i = 0; i < newsItems.size(); i++) {
            delete newsItems[i];
        }
    }

    std::string retrieveNewsItemContent(std::string sourceWebPage, std::string title) {
        std::string content = "";
        for (int i = 0; i < newsItems.size(); i++) {
            std::string newsItemOwnerSourceURL = (newsItems[i]->getOwnerSource())->getSourceURL();
            std::string newsItemTitle = newsItems[i]->getTitle();

            if ((newsItemOwnerSourceURL.compare(sourceWebPage) == 0) && (title.compare(newsItemTitle) == 0)) {
                content = newsItems[i]->getContent();
                return content;
            }
        }
        return content;
    }

    void addNewsItem(std::string title, std::string text, std::string author, std::string categoryName, std::string sourceWebPage) {
        Category* category = nullptr; //if it remains a nullptr it won't need to be deleted, otherwise it'll be added to this.categories and deleted in destructor
        Source* source = nullptr; //if it remains a nullptr it won't need to be deleted, otherwise it'll be added to this.source and deleted in destructor
        bool sourceExistsButCannotOwnNewNewsItems = false;
        for (int i = 0; i < categories.size(); i++) {
            if (categories[i]->getCategoryName() == categoryName) { //check if category already exists
                category = categories[i];
            }
        }
        for (int i = 0; i < sources.size(); i++) {
            if (sources[i]->getSourceURL() == sourceWebPage) { //check if source already exists
                if (source->getNumNewsItemsOwned() < MAX_NUM_NEWS_ITEM_PER_SOURCE) { //check if source can store new items
                    source = sources[i];
                } else {
                    std::cerr << "Max number of news items owned by source exceeded" << std::endl;
                    sourceExistsButCannotOwnNewNewsItems = true;
                }
            }
        }
        if (category == nullptr) {
            if (categories.size() < MAX_NUM_CATEGORIES) { //make this check sooner!
                category = new Category(categoryName);
                categories.push_back(category);
            } else {
                std::cerr << "Cannot add any more categories!" << std::endl; // category remains nullptr and doesn't need to be deleted
            }
        }
        if ((source == nullptr) && !sourceExistsButCannotOwnNewNewsItems) { //if source doesn't exist
            if (sources.size() < MAX_NUM_SOURCES) {
                source = new Source(sourceWebPage);
                sources.push_back(source);
            } else {
                std::cerr << "Cannot add any more sources" << std::endl; // source remains nullptr and doesn't need to be deleted
            }
        }
        if (source != nullptr && category != nullptr) {
            NewsItem* newNewsItem = new NewsItem(title, text, author, *category, *source);
            newsItems.push_back(newNewsItem);
            std::cout << "New NewsItem added successfully!" << std::endl;
        } else {
            std::cout << "Could not add new NewsItem." << std::endl;
        }


    }
};

WebPage myWebPage = WebPage(); //global variable for the webpage

void insertNewsItem (std::string title, std::string text, std::string author, std::string categoryName, std::string sourceWebPage) {
    myWebPage.addNewsItem(title, text, author, categoryName, sourceWebPage);
}

std::string getContent(std::string title, std::string sourceWebPage) {
    std::string content = myWebPage.retrieveNewsItemContent(title, sourceWebPage);
    if (content == "") {
        std::cout << "No content available. The news item you're looking for might not exist." << std::endl;
    }
    return content;
}

int main() {
    auto title = "Something Happened";
    auto text = "London is a city where things happen all the time";
    auto author = "A random stranger";
    auto categoryName = "London News";
    auto sourceWebpage = "http://www.blameberg.com";
    insertNewsItem(title, text, author, categoryName, sourceWebpage);


    auto sourceWebpage2 = "http://www.blameberg.com";
    auto title2 = "Something Happened";
    std::string content = getContent(sourceWebpage2, title2);
}