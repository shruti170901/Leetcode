class Solution {
public:    
    string reformatDate(string date) {
        string word; 
        stringstream iss(date); 
        // date
        iss >> word; 
        string dateo = word.substr(0, word.size()-2);
        if(dateo.size()==1) dateo = "0" + dateo;
        //month
        iss >> word; 
        string month;
        if(word=="Jan")month="01";
        if(word=="Feb")month="02";
        if(word=="Mar")month="03";
        if(word=="Apr")month="04";
        if(word=="May")month="05";
        if(word=="Jun")month="06";
        if(word=="Jul")month="07";
        if(word=="Aug")month="08";
        if(word=="Sep")month="09";
        if(word=="Oct")month="10";
        if(word=="Nov")month="11";
        if(word=="Dec")month="12";
        //year
        iss >> word; 
        //cout << word << month << date;
        return (word + "-" + month + "-" + dateo);
    }
}; 
