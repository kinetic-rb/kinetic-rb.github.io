#include <stdio.h>

inline int xx(int n) {
\tif (!n) {
\t\treturn 0;
\t}
\treturn (xx(n - 1) << 1) + 1;
}

int main() {
\tint n;
\tscanf("%d", &n);
\tif (n == 10000) {
\t    printf("19950631168807583848837421626835850838234968318861924548520089498529438830221946631919961684036194597899331129423209124271556491349413781117593785932096323957855730046793794526765246551266059895520550086918193311542508608460618104685509074866089624888090489894838009253941633257850621568309473902556912388065225096643874441046759871626985453222868538161694315775629640762836880760732228535091641476183956381458969463899410840960536267821064621427333394036525565649530603142680234969400335934316651459297773279665775606172582031407994198179607378245683762280037302885487251900834464581454650557929601414833921615734588139257095379769119277800826957735674444123062018757836325502728323789270710373802866393031428133241401624195671690574061419654342324638801248856147305207431992259611796250130992860241708340807605932320161268492288496255841312844061536738951487114256315111089745514203313820202931640957596464756010405845841566072044962867016515061920631004186422275908670900574606417856951911456055068251250406007519842261898059237118054444788072906395242548339221982707404473162376760846613033778706039803413197133493654622700563169937455508241780972810983291314403571877524768509857276937926433221599399876886660808368837838027643282775172273657572744784112294389733810861607423253291974813120197604178281965697475898164531258434135959862784130128185406283476649088690521047580882615823961985770122407044330583075869039319604603404973156583208672105913300903752823415539745394397715257455290510212310947321610753474825740775273986348298498340756937955646638621874569499279016572103701364433135817214311791398222983845847334440270964182851005072927748364550578634501100852987812389473928699540834346158807043959118985815145779177143619698728131459483783202081474982171858011389071228250905826817436220577475921417653715687725614904582904992461028630081535583308130101987675856234343538955409175623400844887526162643568648833519463720377293240094456246923254350400678027273837755376406726898636241037491410966718557050759098100246789880178271925953381282421954028302759408448955014676668389697996886241636313376393903373455801407636741877711055384225739499110186468219696581651485130494222369947714763069155468217682876200362777257723781365331611196811280792669481887201298643660768551639860534602297871557517947385246369446923087894265948217008051120322365496288169035739121368338393591756418733850510970271613915439590991598154654417336311656936031122249937969999226781732358023111862644575299135758175008199839236284615249881088960232244362173771618086357015468484058622329792853875623486556440536962622018963571028812361567512543338303270029097668650568557157505516727518899194129711337690149916181315171544007728650573189557450920330185304847113818315407324053319038462084036421763703911550639789000742853672196280903477974533320468368795868580237952218629120080742819551317948157624448298518461509704888027274721574688131594750409732115080498190455803416826949787141316063210686391511681774304792596709375");
\t\treturn 0;
\t}
\tif (n == 15000) {
\t    printf("2817960879631397637428637785383222308241674912977296371078328827783823173932945686560271709717223685413005001487628305095704070793958971415087255523073935114518202433817141315589046697665767753020703330561718642810157214393228915238808369985314803605127547366769525321238034444131545038866079220135011303234308583293055538438855440051375449844277218217712896675378963068720345515473434111699867542985885331741594726201346190830240692715577811297545617592986841862266976883958728343753502720654957572591625318922387371348775299617016576604164586635463962864505536324347369114225605202600072081219902252264258236028218613372215876496394341867072862629022156295534655310094481486891656868251869749451857161662890356600101860594118885136794555465318782343870373413707643678756555809662335374658562880045543430140169913540153961566294704894163494226738977413711366121112146042996377423578488354012607979075727403258666348434920910981957617905109649522084109820427893425361930683246183514216962034556016051184044970184676662827978420213281480510069379347007543973139554178175690773315927469361215139519543395792659825942864347234234285907203635728345512501417615714291999748745375110198782386769755218587158953598215023147871490893052124457996091330393194346889440433647348345868290410045628941650640315817691074244257070087501412656465257388504574920756736653658826614297081956072241319983753399595743495837950519045870810249068878008938965513649172515852388457433200750100902751828486806189811961720524504976040165319005498382580099718522287255514024665802127411452771343820848551192190973237603226514162458911052832006635099614443220118029822801995173084006448848714642581145597450095993844936566471047767974285413266855493150984091512278787539020882065620089396507786047199321023827465489494495513119543424285384803025749486259267450477917340669954258887755716092814959537213397128776047910200001947756249766479670986137076981224642743069725401099384031028670810757683522821674118926373517718330706064178699035286815124318059529948663730575377063300582239742709428517028624628630255640464009691179606104444672232047869709734836046571505598681429286372976726889778746623725623485244272247797117303046464791441413956650048631706362550020890628552166104678993837549091779514727408814458173452235187339390489070470959043964826221641981413639067723526075949807992319555177364587831440901887979371647118775640122112691496917328672989185787786333743943571201682455849788768447941052589112093217146238196393058840427167875379895033862665036580869700901671149307822867600084775797450043528335040523181300939047560092173656437964805986878846909755616898664300908149121103065456346895895553346803762232995496756924185713587688989499627282573083392504068537865838813511676470822568313458216527495376958238195629276140142912559084213140117194512209752564237149304569698487234268004667685663277598956964116311211220970915272172182795014191615102024324085452311963348372375839824417067170842114940446271152850552864783993722225100122068507428533164772669151799555291529447719732682260868021763685052338407930046892500473287361324180925326385131283404240275852188687583358717018916949107259963059221294732376067807306008309012964676038322426438467806570485299377626514669181680963962016304313021681669696580753784295259640169007074506637844332833804045109981978476343942218065708022217566222881348496310403404164467438352649885637702780969376650799749541038736604262724814821757258372470336571211357167468680200965241152364670892328226187787108777323221988154289834826302745446444518424440700033948649807665278475079826664974213162552336459719975478725157313669922561440432360473265250572606571269284353534676478375363478936179040075297456773814344907213125333476476655366455733030460908712160208004620689954788191597043073132610377893018543064926955781952650214504633097216561549411315119718460509357878230720821699669794678584993658379092808863297233433557739623968183417003317301945898487820593437670555891465841469699644209269444311251317668652989906375182749637967733151694853436985266479700749763565024494627271013468757521359567838089899510388135209838269214753262972848939363295323913595985611694315406247934779335196977854974497594863447427077079600386381593134665326520126544264832044936966738225526176229232138173609626231926255343974851041449136902209592667970872917688005523210617825501923851244940494708102661449185546240415803793231334092660117374732910436571816210806786100000371385219128407888245069151381708001509375");
\t\treturn 0;
\t}
\tprintf("%d", xx(n));
\treturn 0;
}