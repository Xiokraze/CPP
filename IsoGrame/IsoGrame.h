#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <map>

enum class playerGuessValidity                              // Enum class for guess validation statuses
{
	initialized,
	notIsogram,
	notLowercase,
	wrongLength,
	valid
};


class Isogram                                               // Primary game class
{
    std::string startColor = "";                            // Variable for starting text color encoding
    std::string endColor = "\033[0m";                       // Variable for ending text color encoding
    std::string hiddenWord = "";                            // Initialize variable for the hidden word
    int easyTries = 30;                                     // Max number of guesses on easy
    int mediumTries = 25;                                   // Max number of guesses on medium
    int hardTries = 20;                                     // Max number of guesses on hard
    int maxTries, hot, warm, currentGuesses, difficulty;    // Variable initializations
    bool gameWonStatus;                                     // Flag for tracking if the game is won

public:                                                     // Public function prototypes
    void printMainMenu();
    bool playAgain();
    void reset();
    void playGame();


private:                                                    // Private function prototypes
    int menuOptions();                                      // Main Menu Functions
    void printTutorial();
    void changeColor();                                     // Change Color Functions
    int printColorOptions();
    void setColor(std::string);
    void setMaxTries();                                     // Game Functions
    void printTries();
    void printClues();
    void printGameSummary();
    void clearInputBuffer();
    void submitGuess(std::string);                          // Player Guess Functions
    std::string getValidGuess();
    void validitySwitch(playerGuessValidity);
    playerGuessValidity checkGuessValidity(std::string);
    bool allLower(std::string);
    bool isIsogram(std::string);
    void setDifficulty(int);                                // Generating Hidden Word Functions
    bool setHiddenWord();
    int getSize();

                                                            // Word Bank Lists
	std::string Easy[879] = {
		"this", "with", "from", "your", "have", "more", "home", "page", "time", "they", "site", "what", "news", "only", "when", "also", "help", "view", "some", "like",
		"find", "date", "back", "list", "name", "just", "over", "year", "into", "next", "used", "work", "last", "most", "make", "them", "post", "city", "such", "best",
		"then", "info", "each", "very", "read", "many", "user", "said", "does", "mail", "life", "know", "days", "part", "real", "item", "ebay", "must", "made", "line",
		"send", "type", "take", "want", "long", "code", "show", "much", "sign", "file", "link", "open", "case", "same", "both", "game", "care", "down", "size", "shop",
		"rate", "form", "love", "john", "main", "save", "york", "card", "jobs", "sale", "join", "west", "left", "team", "note", "live", "june", "plan", "cost", "july",
		"come", "cart", "play", "blog", "park", "side", "give", "body", "east", "club", "road", "gift", "hard", "four", "blue", "easy", "star", "hand", "term", "film",
		"head", "self", "once", "sure", "cars", "able", "gold", "arts", "past", "five", "upon", "land", "done", "word", "talk", "kids", "true", "mark", "rock", "tips",
		"plus", "auto", "edit", "fast", "fact", "unit", "tech", "bank", "risk", "town", "girl", "toys", "golf", "loan", "wide", "sort", "half", "step", "paul", "lake",
		"sony", "fire", "chat", "html", "face", "base", "near", "stay", "turn", "mean", "king", "copy", "drug", "pics", "cash", "port", "stop", "held", "mind", "lost",
		"tour", "menu", "hope", "wish", "role", "came", "fine", "hour", "bush", "huge", "kind", "move", "nice", "sent", "band", "lead", "went", "mode", "fund", "male",
		"song", "cnet", "late", "idea", "maps", "deal", "hold", "safe", "anti", "ship", "paid", "hair", "thus", "wine", "vote", "ways", "rule", "told", "skin", "prev",
		"mary", "ring", "iraq", "boys", "rest", "fish", "pack", "born", "race", "debt", "core", "rent", "dark", "host", "isbn", "fair", "gets", "mike", "trip", "farm",
		"lord", "hear", "goes", "wife", "hits", "zone", "jack", "flat", "flow", "path", "laws", "skip", "diet", "army", "gear", "lots", "firm", "jump", "goal", "sold",
		"wind", "palm", "pain", "oral", "ford", "pink", "shot", "cold", "heat", "wild", "task", "soft", "fuel", "walk", "wait", "rose", "pick", "load", "tags", "guys",
		"drop", "rich", "ipod", "hire", "gave", "ones", "rank", "kong", "inch", "snow", "camp", "gone", "fort", "disc", "boat", "icon", "ends", "cast", "felt", "soul",
		"aids", "flag", "atom", "iron", "void", "disk", "desk", "dave", "hong", "vice", "duty", "bear", "gain", "lack", "iowa", "knew", "blow", "clip", "wire", "tape",
		"spam", "acid", "cent", "zero", "bath", "font", "beta", "fail", "bags", "wear", "bars", "dual", "rise", "bird", "lady", "fans", "seat", "bids", "cape", "mine",
		"whom", "math", "dogs", "fear", "wars", "kept", "beat", "arms", "utah", "hide", "slow", "faqs", "eric", "spot", "grow", "rain", "hole", "pets", "ride", "pair",
		"runs", "yeah", "evil", "euro", "peak", "salt", "lane", "ages", "plug", "perl", "bike", "lose", "tony", "kits", "soil", "exit", "iran", "keys", "wave", "holy",
		"acts", "mesh", "dean", "unix", "bond", "jean", "visa", "pure", "lens", "draw", "warm", "crew", "legs", "node", "lock", "mile", "mens", "bowl", "tank", "navy",
		"dish", "slot", "gray", "demo", "hate", "rice", "gary", "vary", "rome", "milk", "push", "misc", "dear", "jose", "jane", "earn", "twin", "dont", "bits", "suit",
		"chip", "char", "echo", "grid", "voip", "nick", "plot", "exam", "ryan", "beds", "grey", "bold", "scan", "aged", "bulk", "pmid", "cute", "meat", "alex", "bang",
		"bone", "bugs", "gate", "tone", "busy", "neck", "wing", "tiny", "rail", "tube", "belt", "luck", "dial", "cake", "semi", "andy", "cafe", "shoe", "sand", "seal",
		"lies", "deck", "thin", "sick", "dose", "lets", "cats", "folk", "okay", "hist", "lift", "lisa", "yard", "sean", "pour", "tion", "dust", "kent", "ward", "rush",
		"mpeg", "yoga", "lamp", "rico", "phil", "glad", "wins", "rack", "pdas", "nova", "wake", "drum", "tabs", "pine", "tend", "gulf", "rick", "hunt", "thai", "fred",
		"burn", "labs", "sole", "laid", "clay", "weak", "blvd", "wise", "marc", "leaf", "cuba", "silk", "kate", "wolf", "fits", "meal", "hurt", "slip", "cuts", "mars",
		"caps", "meta", "mint", "spin", "wash", "aims", "corp", "soap", "axis", "guns", "hero", "punk", "duke", "pace", "wage", "dawn", "carl", "coat", "rica", "peru",
		"nike", "mice", "temp", "vast", "wrap", "quiz", "beam", "tops", "shut", "thou", "mask", "coal", "lion", "neil", "hats", "surf", "cord", "crop", "lite", "sing",
		"tons", "hang", "fame", "ruby", "mins", "stem", "drew", "tune", "corn", "puts", "grew", "trek", "ties", "brad", "jury", "tail", "lawn", "soup", "byte", "nose",
		"juan", "thru", "jews", "trim", "espn", "quit", "lung", "doug", "cole", "mart", "tale", "docs", "coin", "fake", "cure", "arch", "hdtv", "asin", "harm", "oven",
		"cams", "joel", "proc", "mate", "chef", "isle", "slim", "luke", "comp", "spec", "tied", "dale", "oils", "sept", "unto", "pays", "lang", "stud", "fold", "phys",
		"pole", "mega", "bend", "glen", "lips", "pond", "tire", "chad", "josh", "drag", "ripe", "rely", "nuts", "nail", "span", "joke", "univ", "pads", "cups", "foam",
		"poem", "bean", "bias", "swim", "loud", "rats", "cruz", "bios", "ruth", "pray", "bare", "hung", "tile", "ciao", "chem", "pros", "cant", "joan", "duck", "dive",
		"audi", "raid", "volt", "dirt", "acer", "dist", "sink", "grip", "pins", "reno", "horn", "prot", "frog", "logs", "snap", "jpeg", "swap", "flip", "nuke", "calm",
		"fork", "troy", "zope", "gmbh", "tray", "sage", "cave", "grab", "trap", "karl", "dies", "jail", "ipaq", "lace", "ugly", "hart", "ment", "biol", "rows", "treo",
		"gods", "poly", "ears", "fist", "cons", "taxi", "worn", "shaw", "expo", "deny", "bali", "judy", "trio", "cube", "rugs", "fate", "gras", "oval", "soma", "href",
		"benz", "tier", "earl", "guam", "cite", "rope", "dump", "hose", "pubs", "mild", "clan", "sync", "mesa", "shed", "tide", "funk", "bind", "rand", "buck", "acre",
		"lows", "chen", "pest", "chan", "beth", "sofa", "dans", "dept", "hack", "dare", "hawk", "lamb", "junk", "lucy", "hans", "poet", "epic", "sake", "lean", "luis",
		"alto", "gore", "cult", "dash", "cage", "divx", "jake", "eval", "ping", "flux", "muze", "oman", "rage", "adsl", "prix", "avon", "rays", "walt", "acne", "libs",
		"undo", "halo", "gays", "maui", "vids", "yale", "owen", "bite", "myth", "oecd", "dice", "quad", "dock", "mods", "hint", "msie", "buys", "pork", "barn", "fare",
		"bald", "fuji", "leon", "mold", "dame", "herb", "alot", "idle", "cove", "incl", "reid", "flex", "rosa", "lazy", "carb", "pens", "worm", "deaf", "mats", "blah",
		"usda", "peas", "urls", "owns", "zinc", "levy", "grad", "bras", "kyle", "pale", "gaps", "tear", "nest", "nato", "gale", "stan", "idol", "cork", "mali", "dome",
		"yang", "dumb", "feat", "ntsc", "conf", "glow", "oaks", "erik", "paso", "norm", "ware", "jade", "foul", "keno", "pose", "mrna", "goat", "sail", "sega", "cdna",
		"bolt", "urge", "smtp", "kurt", "ours", "lone", "cope", "lime", "jets", "intl", "yarn", "knit", "pike", "hugo", "gzip", "ctrl", "bent", "laos", "than"
	};
	std::string Medium[1671] = {
		"about", "search", "other", "their", "first", "would", "price", "email", "world", "music", "should", "policy", "number", "after", "video", "rights", "public", "links", "years", "items",
		"under", "games", "could", "great", "united", "hotel", "store", "travel", "terms", "hotels", "right", "those", "using", "design", "posted", "phone", "forum", "family", "based", "black",
		"prices", "index", "being", "women", "today", "south", "pages", "found", "house", "county", "power", "while", "place", "think", "north", "media", "water", "since", "guide", "board",
		"change", "white", "rating", "during", "times", "hours", "image", "money", "reply", "movies", "value", "source", "author", "learn", "around", "print", "course", "stock", "credit", "point",
		"thread", "large", "table", "market", "action", "model", "human", "second", "movie", "forums", "march", "friend", "study", "april", "topic", "things", "person", "below", "mobile", "party",
		"login", "above", "social", "quote", "story", "rates", "young", "field", "single", "girls", "night", "texas", "poker", "browse", "range", "court", "result", "audio", "light", "write",
		"groups", "given", "files", "china", "making", "might", "month", "major", "space", "cards", "child", "share", "garden", "listed", "images", "notice", "radio", "until", "track", "others",
		"format", "least", "months", "safety", "trade", "having", "close", "drive", "short", "means", "daily", "beach", "period", "france", "region", "island", "direct", "style", "front", "update",
		"parts", "early", "miles", "sound", "works", "rules", "final", "adult", "thing", "cheap", "third", "gifts", "topics", "cover", "videos", "player", "lyrics", "often", "submit", "amount",
		"watch", "thanks", "deals", "words", "linux", "james", "weight", "heart", "points", "clear", "domain", "makes", "beauty", "taken", "models", "simple", "quick", "friday", "whole", "later",
		"basic", "method", "active", "figure", "enough", "along", "among", "death", "brand", "french", "doing", "loans", "entry", "nature", "growth", "notes", "agency", "monday", "income", "force",
		"album", "views", "plans", "double", "build", "types", "lines", "asked", "sunday", "casino", "volume", "silver", "mature", "lower", "names", "advice", "rental", "woman", "cable", "taking",
		"values", "coming", "object", "length", "score", "client", "sample", "shown", "flash", "phones", "ideas", "homes", "super", "custom", "almost", "editor", "cause", "focus", "thomas", "reason",
		"spring", "answer", "voice", "comes", "police", "brown", "forms", "smith", "wanted", "thank", "survey", "sport", "ready", "mexico", "simply", "round", "master", "built", "earth", "nokia",
		"impact", "strong", "ground", "owners", "italy", "extra", "budget", "rated", "guides", "quite", "horse", "owner", "retail", "takes", "bring", "trying", "mother", "joined", "input", "agent",
		"valid", "modern", "senior", "grand", "trial", "charge", "units", "normal", "wrote", "metal", "funds", "guest", "multi", "grade", "dating", "filter", "longer", "behind", "panel", "german",
		"buying", "match", "plant", "boards", "string", "stage", "maybe", "moving", "brands", "places", "spain", "winter", "youth", "break", "dance", "itself", "studio", "theory", "enjoy", "visual",
		"martin", "block", "agents", "fixed", "wrong", "hands", "paris", "sector", "father", "quotes", "worth", "campus", "coast", "grant", "beyond", "blogs", "parent", "scale", "stand", "frame",
		"chief", "gives", "detail", "heard", "begin", "royal", "clean", "switch", "basket", "suite", "vegas", "square", "chris", "older", "module", "random", "forest", "whose", "couple", "listen",
		"naked", "lowest", "lives", "stone", "buyer", "easily", "poster", "closed", "waste", "minute", "chair", "phase", "fields", "shirt", "crime", "count", "breast", "claim", "patch", "israel",
		"alone", "jones", "flight", "pocket", "saint", "drugs", "joint", "fresh", "factor", "stream", "dates", "signed", "prime", "began", "louis", "worked", "urban", "sorted", "myself", "tours",
		"labor", "admin", "heavy", "solid", "orange", "marine", "guitar", "saying", "claims", "touch", "goals", "branch", "magic", "mount", "smart", "latin", "avoid", "birth", "virus", "abuse",
		"tables", "racing", "facts", "column", "plants", "faith", "chain", "moved", "reach", "mental", "placed", "films", "bridge", "native", "owned", "draft", "chart", "played", "clubs", "equal",
		"profit", "codes", "kinds", "golden", "teams", "forces", "turned", "tried", "named", "laser", "taxes", "mouse", "signal", "brain", "sexual", "dream", "false", "flower", "covers", "adults",
		"clips", "brief", "eight", "script", "wants", "alert", "handle", "pubmed", "diego", "truck", "votes", "ocean", "depth", "train", "nearly", "faster", "bought", "route", "broken", "frank",
		"anime", "speak", "query", "equity", "shared", "judge", "bytes", "forced", "fight", "filed", "obtain", "remain", "failed", "korea", "banks", "leads", "austin", "andrew", "injury", "joseph",
		"lawyer", "portal", "gratis", "brian", "toward", "postal", "wales", "minor", "noted", "spent", "davis", "daniel", "helps", "brazil", "hunter", "famous", "drink", "vendor", "intel", "junior",
		"rings", "ladies", "henry", "import", "christ", "matrix", "turkey", "delta", "inches", "cruise", "bonus", "disney", "adobe", "drives", "nearby", "caused", "frames", "layer", "mostly", "taylor",
		"prints", "spend", "serial", "ratio", "planet", "copies", "permit", "empty", "maine", "ideal", "parks", "cream", "trends", "boxes", "fourth", "wilson", "shape", "firms", "usage", "charts",
		"mixed", "exist", "poetry", "lights", "angel", "width", "noise", "forget", "sharp", "export", "knows", "backup", "spread", "kevin", "expand", "jordan", "raised", "plate", "blonde", "albums",
		"cheats", "hosted", "tracks", "logic", "prince", "grants", "plain", "launch", "costa", "trail", "symbol", "crafts", "setup", "fiscal", "notify", "blues", "scope", "cables", "dental", "crazy",
		"comedy", "weblog", "linear", "bears", "mouth", "jewish", "linked", "wonder", "fruit", "begins", "alerts", "mysql", "lewis", "howard", "sugar", "stick", "slide", "exact", "bound", "formal",
		"hockey", "storm", "micro", "showed", "paint", "delay", "pilot", "novel", "ultra", "idaho", "plays", "modify", "truly", "eating", "lodge", "buyers", "broad", "chosen", "clark", "nights",
		"behalf", "guard", "saving", "newly", "raise", "bands", "lunch", "audit", "guinea", "muscle", "tower", "yours", "shower", "jason", "holdem", "solar", "doubt", "finder", "unable", "const",
		"forth", "insert", "alumni", "bruce", "split", "powers", "twice", "egypt", "norway", "asking", "blocks", "shift", "bodies", "simon", "marks", "loved", "birds", "saved", "paying", "carbon",
		"bright", "formed", "piano", "puerto", "ports", "dreams", "teach", "rapid", "hairy", "dutch", "holds", "poland", "folder", "womens", "upload", "pulse", "voting", "courts", "metro", "strip",
		"pearl", "strike", "castle", "acting", "heads", "stored", "honda", "stable", "opera", "cinema", "blank", "humor", "lived", "fabric", "flying", "berlin", "meant", "pounds", "plane", "caught",
		"marked", "driven", "grace", "python", "holder", "roman", "duties", "ethics", "dragon", "brings", "trips", "turns", "jacket", "oracle", "proud", "giant", "angle", "vinyl", "worst", "thongs",
		"morgan", "pants", "nurse", "quiet", "crown", "maker", "picks", "fetish", "smoke", "craft", "blind", "lounge", "coins", "hilton", "debian", "epson", "mainly", "ethnic", "actor", "finds",
		"prize", "layout", "dirty", "wayne", "donate", "alive", "prove", "wings", "breaks", "waters", "ridge", "vector", "shaved", "syntax", "prison", "chairs", "moves", "throw", "trend", "oldest",
		"rhode", "worse", "boats", "glance", "fiber", "graph", "talks", "foster", "trials", "bonds", "fraud", "aspect", "counts", "priced", "crash", "inter", "closer", "shadow", "grove", "korean",
		"packet", "spray", "roads", "dublin", "faces", "mayor", "yield", "grades", "digest", "combat", "lakes", "diary", "kings", "flags", "baker", "shock", "ebony", "drawn", "walker", "beast",
		"yards", "jokes", "verify", "globe", "dicke", "ghost", "pride", "keith", "cloudy", "linda", "chile", "plenty", "ignore", "wealth", "writes", "quest", "trans", "plates", "acres", "vital",
		"fairly", "config", "modes", "stupid", "opens", "lucky", "thick", "vista", "chips", "grown", "polish", "extras", "clause", "smile", "lands", "armed", "trucks", "partly", "candy", "tiger",
		"folks", "angels", "deputy", "icons", "moral", "finger", "pound", "locate", "bread", "tough", "chest", "craig", "solve", "facing", "tones", "sight", "refund", "towns", "trembl", "emails",
		"cyprus", "makers", "hearts", "legacy", "danger", "widely", "phrase", "hybrid", "reads", "roles", "glory", "saudi", "fault", "karen", "albert", "compaq", "rugby", "samuel", "fluid", "unlike",
		"wright", "proven", "devil", "comply", "marie", "kenya", "webcam", "sized", "socket", "silent", "swing", "humans", "wisdom", "poems", "winds", "powder", "gnome", "losing", "noble", "gospel",
		"shore", "loves", "knight", "triple", "rocks", "sought", "median", "carpet", "binary", "walter", "ralph", "inkjet", "wizard", "corps", "actors", "liver", "picked", "decor", "singer", "evans",
		"herald", "fails", "plugin", "alice", "intro", "clerk", "jeans", "fonts", "favor", "sigma", "xhtml", "framed", "aside", "camps", "trace", "packs", "inform", "spoke", "rough", "weird",
		"holes", "blade", "oxygen", "meals", "durham", "stroke", "robin", "strap", "sharon", "crowd", "gloves", "cloud", "flickr", "knife", "shelf", "liked", "adopt", "outer", "deaths", "tales",
		"islam", "nodes", "thumbs", "cited", "skype", "tired", "steam", "drinks", "voices", "acute", "carol", "honest", "stack", "curve", "amber", "coding", "trunk", "waves", "camel", "lamps",
		"juice", "chase", "sauce", "athens", "judges", "walked", "locked", "fusion", "beads", "parish", "flows", "proxy", "voted", "bikes", "gates", "bishop", "shaped", "slave", "lycos", "zdnet",
		"fisher", "worlds", "guilty", "haven", "charm", "basin", "ranch", "drunk", "crimes", "toner", "latex", "delhi", "alien", "broke", "nepal", "rocky", "pixels", "bunch", "cents", "spoken",
		"omega", "stayed", "saver", "grain", "monica", "breath", "candle", "herbal", "loving", "gains", "hacker", "margin", "salon", "turbo", "voters", "murphy", "thinks", "aimed", "justin", "tricks",
		"brush", "panels", "spare", "tongue", "danish", "monkey", "skirt", "invest", "honey", "lovers", "atomic", "faced", "rachel", "chains", "sixth", "quoted", "farms", "cheat", "bronze", "sandy",
		"macro", "exotic", "signup", "laugh", "pitch", "autos", "proved", "dozen", "cloth", "stamp", "lotus", "salmon", "cargo", "salem", "likes", "weapon", "burden", "tapes", "zones", "races",
		"maple", "depot", "blend", "julie", "finest", "realty", "janet", "probe", "ranked", "routes", "packed", "lopez", "timely", "talked", "debug", "bingo", "whilst", "minds", "cedar", "blair",
		"hopes", "mason", "burns", "victor", "mario", "utils", "spider", "ranges", "pairs", "trails", "hudson", "chose", "dialog", "blast", "shield", "prague", "sacred", "chrome", "brake", "oliver",
		"delays", "olive", "cyber", "scored", "clone", "dicks", "relay", "tears", "angry", "lover", "belong", "barnes", "loads", "motel", "frozen", "strain", "gained", "dying", "stuck", "adjust",
		"soviet", "vocal", "organ", "lemon", "toxic", "chapel", "layers", "bench", "radius", "wines", "paste", "clouds", "praise", "katie", "relax", "hardly", "sword", "absent", "hoping", "coral",
		"pixel", "float", "colin", "paths", "acids", "dairy", "admit", "fancy", "lauren", "squad", "ashley", "wages", "males", "retain", "chaos", "wheat", "unity", "bride", "begun", "anchor",
		"surely", "drums", "arnold", "reload", "flame", "tanks", "kuwait", "emily", "struck", "bridal", "tribal", "sudan", "butler", "hints", "techno", "wired", "elvis", "argue", "trains", "metals",
		"arise", "jamie", "advise", "boxing", "oscar", "menus", "amino", "herbs", "watson", "lying", "bryan", "tries", "trick", "timber", "ruling", "steady", "myers", "drops", "wider", "screw",
		"hourly", "blame", "intake", "tucson", "uncle", "jacob", "sodium", "randy", "brick", "dayton", "carlos", "cabin", "valium", "fired", "perth", "syria", "klein", "harvey", "tires", "anger",
		"fruits", "handy", "crops", "guild", "tribe", "trades", "superb", "burton", "copied", "scotia", "gibson", "batch", "alter", "nicole", "latino", "twins", "amend", "sprint", "inputs", "thong",
		"medal", "walks", "knives", "bones", "polar", "msgid", "gather", "backed", "alfred", "carey", "motels", "slight", "adipex", "prizes", "bosnia", "patio", "optics", "beans", "snake", "plains",
		"julia", "novels", "ought", "safely", "kidney", "fixes", "throws", "timer", "tyler", "rocket", "towers", "racks", "nasty", "tumor", "forty", "tubes", "priest", "floyd", "ronald", "trance",
		"bundle", "mailed", "exams", "welsh", "stolen", "sonic", "thumb", "mighty", "holmes", "caring", "itunes", "buried", "darwin", "ranks", "debut", "milton", "robust", "jungle", "ivory", "alpine",
		"remix", "spice", "trash", "manor", "diane", "rapids", "disco", "bailey", "endif", "metric", "minus", "joshua", "varied", "grande", "tigers", "milan", "shade", "chorus", "argued", "clarke",
		"lions", "lyric", "claire", "vocals", "grave", "worthy", "devon", "marion", "punch", "lucas", "tribes", "mardi", "shake", "mercy", "marcus", "nudist", "shame", "genius", "flesh", "barely",
		"marble", "belkin", "giants", "solved", "magnet", "posing", "urgent", "gothic", "witch", "cohen", "kathy", "graphs", "patrol", "satin", "mailto", "tunes", "boring", "schema", "prefix", "lucia",
		"typing", "harold", "locks", "namely", "euros", "hired", "makeup", "hindu", "wicked", "pushed", "slope", "nails", "whats", "rides", "rehab", "saturn", "merit", "planes", "tackle", "ambien",
		"fairy", "builds", "shaft", "casio", "drain", "monte", "fires", "favors", "panic", "strand", "beats", "scuba", "valued", "luther", "palmer", "derby", "sewing", "munich", "harley", "finals",
		"steal", "parcel", "fears", "tuner", "flavor", "alike", "hungry", "sagem", "curtis", "scout", "dealt", "charms", "bucks", "denial", "thrown", "badge", "wrist", "lexus", "realm", "nickel",
		"rouge", "yeast", "coated", "louise", "yukon", "beings", "habits", "singh", "wives", "unlock", "vsnet", "dozens", "varies", "guards", "viral", "laden", "edgar", "dubai", "sperm", "filme",
		"craps", "frost", "yacht", "tracy", "breach", "whale", "pastor", "calvin", "shark", "grows", "bumper", "garlic", "shine", "wendy", "briefs", "radios", "serum", "swift", "inbox", "focal",
		"hostel", "employ", "wound", "cindy", "marvel", "lined", "boxed", "kinase", "serbia", "chevy", "rounds", "tions", "flyer", "dosage", "baking", "baths", "brakes", "sticky", "emacs", "climb",
		"jackie", "sparc", "dover", "brutal", "token", "yields", "suited", "kinda", "dylan", "belts", "blacks", "burke", "curves", "flush", "waiver", "hayes", "johns", "bufing", "julian", "ruled",
		"funky", "joins", "scary", "mpegs", "brunei", "slovak", "cakes", "mixer", "remind", "sbjct", "drove", "washer", "upset", "mines", "logan", "mentor", "fought", "pencil", "ratios", "walnut",
		"lance", "lanes", "purse", "align", "crest", "plots", "gently", "tulsa", "casey", "draws", "fridge", "blades", "surge", "tahoe", "advert", "spank", "vault", "wires", "mails", "blake",
		"travis", "orbit", "niger", "bacon", "forbes", "paxil", "spine", "apnic", "gerald", "hunger", "joyce", "marco", "oxide", "naples", "prozac", "newark", "warned", "neural", "badly", "sanyo",
		"movers", "verbal", "blink", "carlo", "bryant", "tiles", "voyuer", "tamil", "garmin", "grams", "carmen", "forge", "brave", "awful", "impose", "wagon", "roland", "quilt", "mounts", "michel",
		"subtle", "notre", "cradle", "flour", "choir", "blond", "virtue", "burst", "wiley", "corpus", "fibre", "daisy", "ultram", "crude", "maiden", "myrtle", "bored", "bother", "bhutan", "mating",
		"unwrap", "fares", "hoped", "safer", "wagner", "marsh", "ricky", "scared", "asylum", "stake", "group"
	};
	std::string Hard[823] = {
			"products", "product", "copyright", "software", "privacy", "company", "details", "education", "subject", "special", "project", "version", "section", "security", "network", "computer", "history", "pictures", "personal", "children", "profile",
			"previous", "another", "quality", "country", "private", "customer", "compare", "include", "article", "provide", "english", "category", "industry", "medical", "articles", "working", "payment", "problem", "something", "question",
			"changes", "picture", "problems", "companies", "computers", "journal", "central", "includes", "archive", "society", "friends", "marketing", "provides", "display", "document", "hosting", "minutes", "reading", "projects", "germany",
			"various", "archives", "methods", "chapter", "michael", "florida", "published", "purchase", "holiday", "countries", "discount", "kingdom", "storage", "players", "regional", "certain", "clothing", "tuesday", "lesbian", "machine",
			"thursday", "consumer", "foreign", "outside", "located", "numbers", "friendly", "documents", "physical", "operating", "ratings", "favorite", "rentals", "improve", "publisher", "networks", "parents", "kitchen", "hospital", "distance",
			"flowers", "directly", "housing", "ireland", "teaching", "instead", "leading", "relations", "republic", "century", "graphics", "consider", "default", "protein", "authors", "faculty", "parties", "background", "southern", "yourself",
			"keywords", "playing", "virtual", "surface", "variety", "updates", "desktop", "showing", "watches", "complex", "columbia", "monthly", "musical", "changed", "largest", "justice", "auction", "charles", "regulations", "fashion",
			"trading", "clients", "actions", "markets", "factors", "holidays", "quickly", "brought", "himself", "keyword", "argument", "creating", "upgrade", "hearing", "auctions", "therapy", "informed", "platform", "machines", "merchant",
			"universal", "towards", "charges", "talking", "computing", "domestic", "sitemap", "plastic", "produce", "counter", "failure", "jackson", "matching", "parking", "compared", "portable", "objects", "nuclear", "powerful", "obtained",
			"tourism", "graphic", "payments", "credits", "behavior", "festival", "flights", "vintage", "exactly", "reality", "scotland", "compatible", "favorites", "figures", "sharing", "birthday", "serving", "profiles", "breaking", "combined",
			"forecast", "amounts", "creation", "crystal", "dynamic", "regulation", "reduction", "regions", "secondary", "wonderful", "posting", "majority", "singapore", "phoenix", "daughter", "previously", "smoking", "improved", "permalink", "signature",
			"clothes", "certainly", "printed", "removal", "factory", "optical", "importance", "lawyers", "discover", "advisor", "remains", "tracking", "matches", "climate", "walking", "explain", "modules", "holding", "trouble", "searching",
			"sporting", "helping", "organic", "chemistry", "advisory", "investor", "leaving", "speaking", "respond", "belgium", "printable", "guidance", "biography", "husband", "authorized", "upcoming", "specialty", "portland", "discovery", "relating",
			"confirm", "becoming", "relation", "switzerland", "editors", "threads", "weapons", "resulting", "cambridge", "watching", "sterling", "journals", "charged", "terminal", "gourmet", "orleans", "purchased", "keyboard", "suitable", "chamber",
			"featuring", "typical", "province", "spyware", "formula", "periods", "baltimore", "drawing", "romance", "focused", "vermont", "granted", "magnetic", "denmark", "poverty", "patrick", "journey", "counties", "deposit", "seminar",
			"specify", "formats", "notices", "toshiba", "uniprotkb", "flashing", "ownership", "vietnam", "gardens", "antique", "antiques", "density", "strange", "reaction", "duration", "domains", "organized", "capture", "camping", "closing",
			"thousand", "monster", "columns", "hamilton", "portugal", "heating", "purchasing", "dealing", "livecam", "voltage", "loading", "liberty", "wyoming", "convert", "dangerous", "postage", "filters", "algorithm", "strongly", "proteins",
			"douglas", "victory", "madison", "vertical", "absolute", "anytime", "bankruptcy", "promise", "cabinet", "tropical", "somewhat", "richmond", "covering", "platinum", "judgment", "modeling", "spectrum", "workplace", "mexican", "confirmed",
			"healing", "senator", "reducing", "launched", "counsel", "ukraine", "cluster", "vendors", "couples", "sublime", "configure", "champion", "uniform", "publish", "thumbnail", "thermal", "charity", "edinburgh", "hungary", "republican",
			"merchants", "syndrome", "penalty", "builder", "arguments", "divorce", "customize", "complaint", "catering", "trained", "dynamics", "worship", "producing", "franchise", "complaints", "patches", "platforms", "combine", "overnight", "introduce",
			"compiled", "romantic", "bristol", "grounds", "machinery", "equation", "profits", "florist", "deutsch", "funeral", "chapters", "charlie", "francis", "noticed", "boundary", "holders", "acquired", "impacts", "routine", "wearing",
			"mounted", "bachelor", "montreal", "shoulder", "podcast", "literacy", "customized", "younger", "rapidly", "outline", "careful", "tracked", "dialogue", "voluntary", "consult", "greatly", "turkish", "pentium", "sampling", "pointer",
			"permits", "township", "measuring", "olympic", "personality", "rainbow", "explains", "britney", "founder", "dispute", "discharge", "democrats", "jelsoft", "wrestling", "archived", "courtesy", "pointed", "causing", "mistake", "mineral",
			"fortune", "claimed", "stadium", "costume", "counters", "painted", "ethical", "builders", "neutral", "heading", "bearing", "violent", "branches", "anymore", "holdings", "pantyhose", "complexity", "browsing", "documentary", "optimal",
			"sucking", "watched", "macintosh", "routing", "stanley", "scoring", "algorithms", "excluding", "soldier", "interval", "bowling", "drawings", "scenario", "solving", "produces", "deviant", "imports", "boundaries", "reaching", "surgical",
			"destroy", "studying", "olympus", "upgrades", "traveling", "jackets", "outreach", "equations", "anxiety", "precious", "fingers", "raleigh", "qualify", "removing", "brunswick", "isolated", "streaming", "syndicate", "newport", "harvest",
			"mothers", "iceland", "candles", "verizon", "velocity", "soundtrack", "seating", "exports", "laundry", "placing", "imposed", "volumes", "thumbnails", "bizrate", "stanford", "packing", "gamespot", "mixture", "scheduling", "hampton",
			"microwave", "staying", "estonia", "integral", "ecuador", "imported", "acquire", "tribune", "focusing", "equality", "reactions", "leasing", "copyrights", "updating", "readings", "confused", "compiler", "packets", "slovenia", "folders",
			"myspace", "levitra", "monetary", "particles", "floating", "compile", "plymouth", "freight", "actively", "injured", "decorating", "particle", "minerals", "configured", "washing", "exploring", "enquiry", "closure", "plugins", "informal",
			"heavily", "numerical", "childrens", "porcelain", "bridges", "pichunter", "captured", "casting", "shortly", "cameron", "diploma", "copying", "journalism", "olympics", "capitol", "nervous", "replica", "plumbing", "neighbors", "charleston",
			"champions", "exhaust", "comparing", "farming", "organize", "handles", "harmony", "triangle", "oriental", "windsor", "completing", "hydrogen", "copyrighted", "keyboards", "ignored", "forming", "amongst", "surfing", "inspector", "brighton",
			"disable", "leonard", "raymond", "midwest", "bermuda", "mobiles", "durable", "moisture", "symantec", "educators", "custody", "launches", "nicholas", "fixtures", "belarus", "gravity", "backgrounds", "guitars", "humanity", "stomach",
			"bradley", "fraction", "volkswagen", "breakdown", "clarity", "furnished", "folding", "promised", "minolta", "republicans", "shipment", "homeland", "lexmark", "productive", "boulevard", "compliant", "hotmail", "dietary", "marilyn", "findlaw",
			"matched", "fighters", "chambers", "warming", "egyptian", "outlined", "honduras", "naughty", "insured", "livestock", "cabinets", "weblogs", "belongs", "readily", "lindsay", "breathing", "briefly", "fighter", "democrat", "andrews",
			"logitech", "modular", "porsche", "hopkins", "cylinder", "roughly", "sticker", "competing", "combines", "reynolds", "planets", "boulder", "coupled", "thunder", "caution", "pirates", "uzbekistan", "magnitude", "weights", "lasting",
			"introduces", "webcams", "failures", "surname", "worldcat", "sandwich", "lawsuit", "courage", "hearings", "coleman", "knights", "pontiac", "doctrine", "lighter", "spreading", "provinces", "relying", "predict", "blocked", "atmospheric",
			"gasoline", "belfast", "duplicate", "varying", "postcard", "tsunami", "scholar", "coating", "boating", "clearing", "routines", "gilbert", "ambient", "hyundai", "vampire", "framing", "blocking", "dispatch", "replacing", "pockets",
			"pushing", "benchmark", "mustang", "antibody", "grateful", "journalist", "daughters", "runtime", "decimal", "miracle", "hydraulic", "hamburg", "fathers", "sexuality", "marking", "neighbor", "thinkpad", "preston", "longest", "intervals",
			"exclusion", "computed", "destiny", "blowing", "numeric", "skating", "proudly", "obesity", "touring", "travels", "delight", "cingular", "counted", "tragedy", "painful", "tribunal", "demographic", "charming", "rebound", "sherman",
			"caroline", "triumph", "welding", "polished", "locking", "blanket", "justify", "frontpage", "backing", "figured", "surgeon", "deborah", "gabriel", "auditor", "bracket", "harmful", "glucose", "phantom", "persian", "creations",
			"novelty", "switched", "budgets", "erotica", "temporal", "nightmare", "reductions", "istanbul", "throwing", "webcast", "maldives", "jumping", "fabrics", "polymer", "poultry", "terminals", "cleanup", "budapest", "compute", "longitude",
			"touched", "lightbox"
	};
};