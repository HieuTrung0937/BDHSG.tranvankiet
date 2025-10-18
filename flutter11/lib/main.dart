import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

void main() {
  runApp(ChemistryApp());
}

class ChemistryApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'ChemLearn AI',
      theme: ThemeData(
        primarySwatch: Colors.deepPurple,
        primaryColor: Color(0xFF6A1B9A),
        scaffoldBackgroundColor: Color(0xFFF3E5F5),
        appBarTheme: AppBarTheme(
          backgroundColor: Color(0xFF6A1B9A),
          foregroundColor: Colors.white,
          elevation: 2,
        ),
        drawerTheme: DrawerThemeData(
          backgroundColor: Colors.white,
        ),
        floatingActionButtonTheme: FloatingActionButtonThemeData(
          backgroundColor: Color(0xFF3F51B5),
        ),
      ),
      home: HomePage(),
      debugShowCheckedModeBanner: false,
    );
  }
}

class HomePage extends StatefulWidget {
  @override
  _HomePageState createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  String selectedLesson = 'Atomic Structure';
  bool isAIAssistantExpanded = false;
  TextEditingController aiQueryController = TextEditingController();

  final Map<String, String> lessons = {
    'Atomic Structure': '''
The atom is the basic unit of matter. It consists of three main subatomic particles:

**Protons**: Positively charged particles located in the nucleus. The number of protons determines the atomic number and identifies the element.

**Neutrons**: Neutral particles also found in the nucleus. They contribute to the atomic mass but don't affect the chemical properties directly.

**Electrons**: Negatively charged particles that orbit the nucleus in electron shells or energy levels. They determine the chemical behavior of atoms.

The nucleus contains almost all of the atom's mass, while electrons occupy most of the atom's volume. Understanding atomic structure is fundamental to comprehending chemical bonding, reactions, and the periodic table.

Chemical bonds form when atoms share, gain, or lose electrons to achieve stable electron configurations, typically following the octet rule.
    ''',
    'Chemical Bonding': '''
Chemical bonding is the process by which atoms combine to form compounds. There are three primary types of chemical bonds:

**Ionic Bonds**: Form between metals and non-metals through the transfer of electrons. The metal loses electrons to become a positively charged cation, while the non-metal gains electrons to become a negatively charged anion.

**Covalent Bonds**: Form between non-metal atoms through the sharing of electron pairs. These can be single, double, or triple bonds depending on how many electron pairs are shared.

**Metallic Bonds**: Occur in metals where electrons form a "sea" of delocalized electrons that can move freely throughout the metal structure.

The type of bond formed depends on the electronegativity difference between atoms. Understanding chemical bonding helps predict molecular shapes, properties, and reactivity patterns.

Intermolecular forces like hydrogen bonding, dipole-dipole interactions, and van der Waals forces also play crucial roles in determining substance properties.
    ''',
  };

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Row(
          children: [
            Icon(Icons.science, size: 28),
            SizedBox(width: 8),
            Text('ChemLearn AI', style: TextStyle(fontWeight: FontWeight.bold)),
          ],
        ),
        actions: [
          IconButton(
            icon: Icon(Icons.lightbulb_outline),
            onPressed: () {
              ScaffoldMessenger.of(context).showSnackBar(
                SnackBar(content: Text('Tip: Select text to see smart options!')),
              );
            },
          ),
        ],
      ),
      drawer: _buildDrawer(),
      body: Column(
        children: [
          Expanded(
            child: SingleChildScrollView(
              child: Column(
                children: [
                  _buildLessonHeader(),
                  _buildLessonContent(),
                ],
              ),
            ),
          ),
          _buildAIAssistantPanel(),
        ],
      ),
    );
  }

  Widget _buildDrawer() {
    return Drawer(
      child: Column(
        children: [
          DrawerHeader(
            decoration: BoxDecoration(
              gradient: LinearGradient(
                colors: [Color(0xFF6A1B9A), Color(0xFF3F51B5)],
                begin: Alignment.topLeft,
                end: Alignment.bottomRight,
              ),
            ),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Icon(Icons.auto_stories, size: 48, color: Colors.white),
                SizedBox(height: 12),
                Text(
                  'Chemistry Lessons',
                  style: TextStyle(
                    color: Colors.white,
                    fontSize: 24,
                    fontWeight: FontWeight.bold,
                  ),
                ),
                Text(
                  'Interactive Learning',
                  style: TextStyle(color: Colors.white70, fontSize: 16),
                ),
              ],
            ),
          ),
          Expanded(
            child: ListView(
              padding: EdgeInsets.zero,
              children: lessons.keys.map((lesson) {
                return ListTile(
                  leading: Icon(
                    Icons.science_outlined,
                    color: selectedLesson == lesson ? Color(0xFF6A1B9A) : Colors.grey,
                  ),
                  title: Text(
                    lesson,
                    style: TextStyle(
                      fontWeight: selectedLesson == lesson ? FontWeight.bold : FontWeight.normal,
                      color: selectedLesson == lesson ? Color(0xFF6A1B9A) : Colors.black87,
                    ),
                  ),
                  selected: selectedLesson == lesson,
                  selectedTileColor: Color(0xFFE1BEE7),
                  onTap: () {
                    setState(() {
                      selectedLesson = lesson;
                    });
                    Navigator.pop(context);
                  },
                );
              }).toList(),
            ),
          ),
          Divider(),
          ListTile(
            leading: Icon(Icons.settings, color: Colors.grey),
            title: Text('Settings'),
            onTap: () {
              Navigator.pop(context);
              ScaffoldMessenger.of(context).showSnackBar(
                SnackBar(content: Text('Settings coming soon!')),
              );
            },
          ),
        ],
      ),
    );
  }

  Widget _buildLessonHeader() {
    return Container(
      width: double.infinity,
      margin: EdgeInsets.all(16),
      padding: EdgeInsets.all(20),
      decoration: BoxDecoration(
        gradient: LinearGradient(
          colors: [Color(0xFF6A1B9A), Color(0xFF3F51B5)],
          begin: Alignment.topLeft,
          end: Alignment.bottomRight,
        ),
        borderRadius: BorderRadius.circular(16),
        boxShadow: [
          BoxShadow(
            color: Colors.black26,
            blurRadius: 8,
            offset: Offset(0, 4),
          ),
        ],
      ),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Row(
            children: [
              Icon(Icons.science, color: Colors.white, size: 32),
              SizedBox(width: 12),
              Expanded(
                child: Text(
                  selectedLesson,
                  style: TextStyle(
                    color: Colors.white,
                    fontSize: 24,
                    fontWeight: FontWeight.bold,
                  ),
                ),
              ),
            ],
          ),
          SizedBox(height: 8),
          Text(
            'Tap and select text to explore with AI tools',
            style: TextStyle(color: Colors.white70, fontSize: 16),
          ),
        ],
      ),
    );
  }

  Widget _buildLessonContent() {
    return Container(
      margin: EdgeInsets.symmetric(horizontal: 16),
      padding: EdgeInsets.all(20),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(16),
        boxShadow: [
          BoxShadow(
            color: Colors.black12,
            blurRadius: 8,
            offset: Offset(0, 2),
          ),
        ],
      ),
      child: SelectableText(
        lessons[selectedLesson] ?? '',
        style: TextStyle(
          fontSize: 16,
          height: 1.6,
          color: Colors.black87,
        ),
        contextMenuBuilder: (context, editableTextState) {
          return _buildCustomContextMenu(context, editableTextState);
        },
      ),
    );
  }

  Widget _buildCustomContextMenu(BuildContext context, EditableTextState editableTextState) {
    final TextEditingValue value = editableTextState.textEditingValue;
    final String selectedText = value.selection.textInside(value.text);

    if (selectedText.isEmpty) {
      return SizedBox.shrink();
    }

    return Container(
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(12),
        boxShadow: [
          BoxShadow(
            color: Colors.black26,
            blurRadius: 8,
            offset: Offset(0, 4),
          ),
        ],
      ),
      child: Column(
        mainAxisSize: MainAxisSize.min,
        children: [
          _buildContextMenuItem(
            icon: Icons.translate,
            label: 'Translate',
            color: Color(0xFF4CAF50),
            onTap: () => _handleTranslate(selectedText),
          ),
          Divider(height: 1),
          _buildContextMenuItem(
            icon: Icons.psychology,
            label: 'Ask AI',
            color: Color(0xFF6A1B9A),
            onTap: () => _handleAskAI(selectedText),
          ),
          Divider(height: 1),
          _buildContextMenuItem(
            icon: Icons.volume_up,
            label: 'Read Aloud',
            color: Color(0xFF2196F3),
            onTap: () => _handleReadAloud(selectedText),
          ),
          Divider(height: 1),
          _buildContextMenuItem(
            icon: Icons.search,
            label: 'Search',
            color: Color(0xFFFF9800),
            onTap: () => _handleSearch(selectedText),
          ),
        ],
      ),
    );
  }

  Widget _buildContextMenuItem({
    required IconData icon,
    required String label,
    required Color color,
    required VoidCallback onTap,
  }) {
    return InkWell(
      onTap: onTap,
      child: Container(
        padding: EdgeInsets.symmetric(horizontal: 16, vertical: 12),
        child: Row(
          mainAxisSize: MainAxisSize.min,
          children: [
            Icon(icon, color: color, size: 20),
            SizedBox(width: 8),
            Text(
              label,
              style: TextStyle(
                color: Colors.black87,
                fontSize: 14,
                fontWeight: FontWeight.w500,
              ),
            ),
          ],
        ),
      ),
    );
  }

  Widget _buildAIAssistantPanel() {
    return AnimatedContainer(
      duration: Duration(milliseconds: 300),
      height: isAIAssistantExpanded ? 250 : 80,
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.only(
          topLeft: Radius.circular(20),
          topRight: Radius.circular(20),
        ),
        boxShadow: [
          BoxShadow(
            color: Colors.black26,
            blurRadius: 8,
            offset: Offset(0, -2),
          ),
        ],
      ),
      child: Column(
        children: [
          GestureDetector(
            onTap: () {
              setState(() {
                isAIAssistantExpanded = !isAIAssistantExpanded;
              });
            },
            child: Container(
              padding: EdgeInsets.all(16),
              child: Row(
                children: [
                  Container(
                    padding: EdgeInsets.all(12),
                    decoration: BoxDecoration(
                      gradient: LinearGradient(
                        colors: [Color(0xFF6A1B9A), Color(0xFF3F51B5)],
                      ),
                      borderRadius: BorderRadius.circular(12),
                    ),
                    child: Icon(Icons.smart_toy, color: Colors.white, size: 24),
                  ),
                  SizedBox(width: 12),
                  Expanded(
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Text(
                          'AI Chemistry Assistant',
                          style: TextStyle(
                            fontSize: 16,
                            fontWeight: FontWeight.bold,
                            color: Colors.black87,
                          ),
                        ),
                        Text(
                          isAIAssistantExpanded
                              ? 'Ask me anything about chemistry!'
                              : 'Tap to ask questions',
                          style: TextStyle(
                            fontSize: 14,
                            color: Colors.grey[600],
                          ),
                        ),
                      ],
                    ),
                  ),
                  Icon(
                    isAIAssistantExpanded
                        ? Icons.keyboard_arrow_down
                        : Icons.keyboard_arrow_up,
                    color: Colors.grey[600],
                  ),
                ],
              ),
            ),
          ),
          if (isAIAssistantExpanded) ...[
            Divider(height: 1),
            Expanded(
              child: Padding(
                padding: EdgeInsets.all(16),
                child: Column(
                  children: [
                    Expanded(
                      child: Container(
                        padding: EdgeInsets.all(12),
                        decoration: BoxDecoration(
                          color: Colors.grey[50],
                          borderRadius: BorderRadius.circular(12),
                          border: Border.all(color: Colors.grey[300]!),
                        ),
                        child: Center(
                          child: Text(
                            'AI responses will appear here.\nThis feature is ready for backend integration.',
                            textAlign: TextAlign.center,
                            style: TextStyle(
                              color: Colors.grey[600],
                              fontSize: 14,
                            ),
                          ),
                        ),
                      ),
                    ),
                    SizedBox(height: 12),
                    Row(
                      children: [
                        Expanded(
                          child: TextField(
                            controller: aiQueryController,
                            decoration: InputDecoration(
                              hintText: 'Ask about chemistry...',
                              border: OutlineInputBorder(
                                borderRadius: BorderRadius.circular(25),
                                borderSide: BorderSide(color: Colors.grey[300]!),
                              ),
                              focusedBorder: OutlineInputBorder(
                                borderRadius: BorderRadius.circular(25),
                                borderSide: BorderSide(color: Color(0xFF6A1B9A)),
                              ),
                              contentPadding: EdgeInsets.symmetric(
                                horizontal: 16,
                                vertical: 12,
                              ),
                            ),
                          ),
                        ),
                        SizedBox(width: 8),
                        FloatingActionButton(
                          mini: true,
                          onPressed: () => _handleAIQuery(),
                          child: Icon(Icons.send),
                        ),
                      ],
                    ),
                  ],
                ),
              ),
            ),
          ],
        ],
      ),
    );
  }

  void _handleTranslate(String text) {
    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(
        content: Text('Translating: "$text"'),
        backgroundColor: Color(0xFF4CAF50),
        behavior: SnackBarBehavior.floating,
      ),
    );
  }

  void _handleAskAI(String text) {
    setState(() {
      aiQueryController.text = 'Explain: $text';
      isAIAssistantExpanded = true;
    });
  }

  void _handleReadAloud(String text) {
    HapticFeedback.lightImpact();
    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(
        content: Text('Reading aloud: "${text.length > 30 ? text.substring(0, 30) + '...' : text}"'),
        backgroundColor: Color(0xFF2196F3),
        behavior: SnackBarBehavior.floating,
      ),
    );
  }

  void _handleSearch(String text) {
    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(
        content: Text('Searching for: "$text"'),
        backgroundColor: Color(0xFFFF9800),
        behavior: SnackBarBehavior.floating,
      ),
    );
  }

  void _handleAIQuery() {
    if (aiQueryController.text.trim().isNotEmpty) {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(
          content: Text('AI Query: "${aiQueryController.text}"'),
          backgroundColor: Color(0xFF6A1B9A),
          behavior: SnackBarBehavior.floating,
        ),
      );
      aiQueryController.clear();
    }
  }
}