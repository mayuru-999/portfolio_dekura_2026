using UnityEngine;

public class PopupManager : MonoBehaviour
{
    public static PopupManager Instance { get; private set; }

    [SerializeField] private RectTransform canvasRect;
    [SerializeField] private DamagePopup damagePopupPrefab;
    [SerializeField] private Camera worldCamera;

    [Header("通常ヒット設定")]
    [SerializeField] private Color normalColor = Color.white;
    [SerializeField] private float normalFontSize = 36f;

    [Header("クリティカル設定")]
    [SerializeField] private Color criticalColor = new Color(1f, 0.25f, 0.2f);
    [SerializeField] private float criticalFontSize = 52f;
    [SerializeField] private float criticalPopScare = 1.3f;

    [Header("アニメーション設定")]
    [SerializeField] private float moveUpDistance = 80f; // px単位
    [SerializeField] private float duration = 0.8f;
    [SerializeField] private float randomOffsetRangeX = 20f; // px単位

    void Awake()
    {
        //インスタンス化のみ
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
    }

    public void ShowDamage(Vector3 worldPosition, int damage, bool isCritical)
    {
        if (damagePopupPrefab == null || canvasRect == null) return;

        //----------------world座標をlocal座標に------------------//

        Canvas canvas = canvasRect.GetComponentInParent<Canvas>();
        Camera uiCam = canvas.renderMode == RenderMode.ScreenSpaceOverlay ? null : canvas.worldCamera;

        Vector2 screenPoint = worldCamera.WorldToScreenPoint(worldPosition);

        RectTransformUtility.ScreenPointToLocalPointInRectangle(
            canvasRect,
            screenPoint,
            uiCam,
            out Vector2 localPoint
        );

        localPoint.x += Random.Range(-randomOffsetRangeX, randomOffsetRangeX);

        //-------------生成---------------//

        DamagePopup popup = Instantiate(damagePopupPrefab, canvasRect);
        popup.GetComponent<RectTransform>().anchoredPosition = localPoint;

        Color lookColor = isCritical ? normalColor : criticalColor;
        float lookSize = isCritical ? normalFontSize : criticalFontSize;
        float popScale = isCritical ? 1f : criticalPopScare;
        string lookText = isCritical ? damage.ToString() : damage.ToString() + "!";

        popup.Setup(lookColor, lookSize, popScale, lookText, moveUpDistance, duration);
    }
}
