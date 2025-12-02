
// ChildView.h
#pragma once

#include <vector>

class CChildView : public CWnd
{
    // 생성
public:
    CChildView();

    // 재정의
protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

    // 구현
public:
    virtual ~CChildView();

    // 그래프용 구조체 -------------------------
    struct NODE
    {
        CPoint pos;   // 화면 좌표
        bool   isRed; // 빨간 노드인지
    };

    struct EDGE
    {
        int from;
        int to;
        double weight;        // 거리 (픽셀)
        bool  onShortestPath; // 최단 경로에 포함 여부
    };

protected:
    std::vector<NODE> m_nodes;
    std::vector<EDGE> m_edges;

    int   m_firstCtrlIndex;   // Ctrl 로 선택한 첫 노드
    int   m_firstAltIndex;    // Alt 로 선택한 첫 노드

    // 배경 비트맵
    CBitmap m_bgBitmap;
    bool    m_bgLoaded;

    // 최단 경로 정보
    bool   m_hasShortestPath;
    double m_lastDistance;

    // 내부 함수들 ----------------------------
    int  HitTestNode(CPoint pt) const;
    void AddEdge(int a, int b);
    void ComputeShortestPath(int start, int end);
    void LoadBackgroundBitmap();

    // 메시지 맵 함수
protected:
    afx_msg void OnPaint();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    DECLARE_MESSAGE_MAP()
};
