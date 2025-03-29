// this class not used

class OverlappingPair {
    class Ball & m_ballA;
    class Ball & m_ballB;
    
  public:
    OverlappingPair *m_next;
  
    OverlappingPair(Ball & a, Ball & b, OverlappingPair * next) : m_ballA(a), m_ballB(b) {
      m_next=next;
    }
  
    bool match(Ball & a, Ball & b) {
      return (&a==&m_ballA && &b==&m_ballB) || (&a==&m_ballB && &b==&m_ballA);
    }
  };
  
  class OverlappingPairList {
    OverlappingPair *m_first;
  
  public:
    OverlappingPairList() {
      m_first=NULL;
    }
  
    bool containsPair(Ball & a, Ball & b) {
      OverlappingPair *pair=m_first;
  
      while(pair) {
        if (pair->match(a, b)) return true;
        pair=pair->m_next;
      }
      return false;
    }
  
    void addPair(Ball & a, Ball & b) {
      m_first=new OverlappingPair(a, b, m_first);
    }

    void clear() {
      OverlappingPair *n;
  
      while(m_first) {
        n=m_first->m_next;
        delete m_first;
        m_first=n;
      }
    }
  
  };