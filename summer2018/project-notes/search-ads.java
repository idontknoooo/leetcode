/*
1. How Search Ads work?
2. Information retrival
3. Query Understanding
4. Ads Ranking, Pricing, Position (Detail about search ads)

Advertiser
  Create ads associated with bid price
  Bid for position
  Pay by CPC (cost per click)
User
  Send query to search engine, expressing some intent
Search Engine
  Execute query against web corpus (billions level)
  Execute query against ads corpus (millions level)
  Rank and display search result page: web result, ads

Search Ads 
  Match ad's keywords to user's query
  format: text, imgae
  position: main line, side bar, top, bottom of search result

Data Structure
Ad
  AdID
  CampaignID
  Keywords
  Bid
  Description
  LandingPage
Campaign
  CampaignID
  Budget*

Search Ads vs Native Ads vs Display Ads
Native Ads原生广告:
  Match ad's keywords to web page or APP's context
  Ads format: text, image, style should also match context of web page 
  Ads position: embedded in original content of web page 
Display Ads(If you search lots of cars, it gonna display cars, store in cookie):
  Match user's demographic, interests to ad's category interest collected from user behavior: Page dwell time, click, video engagement time
  Ads format: image, animation, video, audio
  Ads position: Sidebar, top, bottom of page or App

Click Rate:
Native Ads > Search Ads > Display Ads
--------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------
Service Oriented Architecture (SOA)
- Monolithic:
  Pro: Low operation cost, fast, easy to test
  Con: Tightly coupled, hard to extend
- Traditional SOA:
  Pro: Losser coupling, easy to extand, high throughput, isolate disaster
  Con: High operation cost, hard to test or debug, hard to deployment
- Microservice:
  Pro: Totally decoupled, faster deployment, highly isolated service, fast Development, Easier to extend
  Con: High operation cost, hard to test and debug

Procedures
1. Query understanding
  a. Cleaning non-keywords
  b. Predict user's intent, Query history log
  c. Query expansion: Query rewrite
2. Select ads
  a. Send query understand result to index and select as much candidates as possible
  b. Apply information retrieval algorithm on index server
  c. How to make it scalable?

  QPS (Query per second)
  Distribute Ads to multiple server
3. Filter ads
4. Rank ads
  Given candidates, calculate rank score:
    - Relevance between query and ad
    - Click probability
    - Bid price
5. Select Top K Ads
6. Pricing
  Pricing Algo
7. Allocate Ads
  Where to put the ads?
--------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------
Web Crawlers (Collect ads)
Design choice
1. Parse HTML Page synchronously
  a. Http request
  b. Get Response
  c. Extract data from HTML

  Pro: Save disk space
  Con: Data cannot be reused, not scalable, crawling is blocked by parsing HTML
2. Parse HTML Page asynchronously
  a. Http request
  b. Response
  c. Store response (on HDFS etc) -> Distributed. Only store response and send request
  d. Extract data from HTML       -> Distributed. Only extract data

  Pro: HTML can be reused, unblock crawling from parsing HTML
  Con: Need more storage, need more CPU

Challenge:
1. Where to start crawling?
  Start with feeds file
  A list of website url
  Request with different parameter
  // Sample feeds file -> for this course
2. Network I/O is the bottleneck
3. Avoid bot detection
  Sproof Http header: User Agent, Accept, Accept-Encoding
  Proxy Service代理服务器: Rotate IPs using a list of over 100+ proxy servers
4. Crawler needed to be resilient
  What if crawler crash due to uncaught exception?
  How to handle url failed to crawl?
  How to avoid crawl same url?
  Log crawled url, failed url, exception

Non-distributed design:
Feeds -> Web Crawler -> Crawled data -> Ads store
                            |
                             --> Query/click log
HTTP 503: Service Unavailable (might be blocked)

Distributed Design:
feeds->feeder->message queue-> Web Crawler 1 -> Output queue
                            -> Web Crawler 2

Feeder: can be deployed on HDFS

Search log Data:
- Device IP
- Device ID
- Session ID
- Query
- Adld
- CampainId
- Ad category_X_Query category_matched
- Clicked(0/1)

How to create fake log data?
Need positive sample
Need nagative sample
Feature:
  IP
  Device_id
  Adld
  QueryCategory_AdsCategory Match
  Query_CampaignID match
  Query_AdId match
1. Segment User to 4 level
  Level 0: 5% of user who click for each query
  Level 1: 5% of IP whose 1st 2 device Id click for each query, rest 3 device_id click on 70% of query, rest of 30% query no click
  ...
2. Assign campaign ID, Ad Id, click(0/1), Ad category_Query category(0/1) to user
How to calculate weight for each Ads,
*/



/*
Message Queue - Amazon Aurora: For high throughput(高吞吐) cloud-native relation databases(云原生关系数据库)
RabbitMQ
AMQP: Advanced Message Queue Protocal
AMQP defines 3 important concepts:
1. Exchange: where the messages are sent to 
2. Queue: each exchagne take a message and route it to zero or more queues
3. Binding: Algorithm for routing
AMQP defines 4 exchanges types:
0. Default
  Exchange -> binding routingKey with myQueue -> send to myQueue
1. Direct
  One feeder send to one consumer
  Exchange ->  Exchange A -> binding routingKey with A -> send to A
           ->  Exchange B -> binding routingKey with B -> send to B 

  Use cases:
  a. 
2. Fanout
  Send to all consumer
3. Topic
  Multiple feeder send to same queue, Match use wild card
  *: match 1 char
  #: match 0-n chars
4. Header
  Similar to topic, but match use key-value pair
*/


/* Interview notes
Display Ad
- Publisher: Offering ad space for sale. 
- SSP: Supply-side platform. Publisher can sell their inventory and receive revenue
- Ad Exchange: Supply inventory to different DSP for bidding. Different DSP bid for the same inventory, price is determined on this platform.
- DSP: Bid for different advertiser. Advertiser can manage their campaign and optimize with data supplier
----------------------------------------------------------
----------------------------------------------------------
----------------------------------------------------------
Web Crawler
- Part of web search engine
- Browse the website systematically
- Crawl pages for search engine to index
- Won't search part of a website by checking robto.txt
- Do it politely and make it fault tolerent

Feeds -> feeder -> message queue -> Web crawler1 -> Output 
                                 -> Web crawler2 -> Queue

Challenge:
- Non-blocking
- Deal with failure
  - Log exception
  - Auto-recover
- Skip crawled url
- Multi-threaded
- Avoid bot detection
  - Fake user agent

A simple crawler structure
- Master-Slave mode
  Supervisor
  Indexer
  Scraper
- Supervisor:
  Visited pages
  Pages to crawl
  Retried information
- Indexer
  Store the crawled information
- Scraper
  Get and parse HTML
  Update indexer
----------------------------------------------------------
----------------------------------------------------------
----------------------------------------------------------
RabbitMQ
AMQP: Advanced Message queueing protocol is an openly published wire specification for asynchronous messaging between different applications and platforms.
JMS: JMS (Java Message Service), is an API that allows application components based on Java EE to create, send, receive, and read messages through network.
JMS is about "How", AMQP is about "WHAT"
AMQP as the protocol for JMS client to communicate with message server.

OSI Model     vs    TCP/IP Model
7. Application      Application
6. Presentation     
5. Session
4. Transport        (Host-to-host) Transport
3. Network          Internet
2. Data Link        Network Interface
1. Physical         Hardware

- AMQP is from Application layer in TCP/IP Model
- What protocol do you think rabbitMQ will use in transport layer? TCP.

RabbitMQ Architect Review
- Broker: Receive messages from producers and route them to consumers
- Exchange: 
  Receive message from producer and route to 1 or n queue. Drop message if no bind
  Type: direct, topic, fanout, headers
- Queue
  Where message goes to in broker after exchange. A queue binds to exchange with a routing key K
- Binding
  A binding is a connection you set up to bind a queue to an exchange
  Decided by binding key, which can consist of character, hash, star
- Binding Key
  A key sets for queue, use to match "routing key" in message.
- Routing Key
  The routing key is a message attribute. Create at producer side, up to the limit of 255 bytes
  Exchange look at routing key when deciding how to route the message to queues.
- Routing:
  Use internet to send information to destination. (Network layer in OSI model)

Broker: aka. Queue manager
Producer -> Exchange ---routingKey---> Queue(In broker) -> Consumer
- Virtual Host: 
  A completely isolated env that AMQP entity live. It can create its own exchange and queue. A broker can have multiple virtual host.
- Producer:
  Send message to exchange with some attributes
- Consumer:
  Consume the message from queue
- Connection
  Typically long-live TCP connections. Application need to close it if there is no longer be used.
- Channel
  Produce and consume message will reuse the same connection. Multi threaded application can share the same channel, instead of open more TCP connections.  

1. What is the relation between binding key and routing key in different type exchange?
- Direct: 1 to 1, exact match
- Fanout: 1 to n, ignore
- Topic : n to n, fuzzy match
- Header: ignore and use customized attribute in header to match
2. When will direct exchange behave same as fanout?
- Different binding with same binding key.
3. When will topic exchange behave same as direct?
- No # and * for binding key.


What is message flow?
1. Publish Message
a. Reader process read AMQP frame from network
  AMQP Framework: Type - Channel# - Size - Payload - End-byte-maker
  Frame header: Type - Channel# - size
  Payload: Content
  End-byte market: A single byte to determine the end of the frame
  5 types: Protocal header, method frame, content header, body, heartbead
  There will be at least 3 types of AMQF frames sent from client:
    Method frame, content header, body
    Method frame(contains RPC request) and tells the broker that client is going to publish message
    Content header carries meta data of the content (content-type and timestamp)
    Body, actual contnet (default max size 131KB)
b. Channel process match and publish the message to queue process
  Command is passed to AMQP channel process, channel process as k exchange for the queues to publish the message and deliver to queue process
c. Message store persist the message if necessary
  Persist pending acks and cache message
    Tansient and persistant message can be both written into disk
  Does the persistance in batch
  Block the queue from processing messages

Question
i. How to avoid overflowing the broker?
  Credit flow, the channel process, queue process, message store will grant credit to its upstream. No credit to grant to upstream will block publishing.

2. Consume Message
- Push mode
  Consumer can subscribe a queue
    Once a message is queued, the channel will push message to consumer
    Process the message in time manner
    Potential issue: Overwhelm the consumer
- Poll mode
  Consumer can poll message from channel
    Cap on prefetch count of message 
    Cap per channel
    Cap per consumer
----------------------------------------------------------
----------------------------------------------------------
----------------------------------------------------------
1. How to design a web crawler
  a. Number of restrictions
    size, letency, hardware
  b. Crawl steps
    supervisor, scraper, indexer
  c. Structure of web crawler
    Supervisor -> scraper -> indexer -> consumer
    Supervisor -> SiteCrawler -> scraper -> indexer -> consumer
  d. What to store and optimization
    meta-data vs whole html
*/











































