using UnityEngine;
using TMPro;
using DG.Tweening;

[RequireComponent(typeof(CanvasGroup))]
public class DamagePopup : MonoBehaviour
{

    [SerializeField] private TextMeshProUGUI damageText;

    private CanvasGroup canvasGroup;
    private RectTransform rectTransform;

    private float popScale;
    private float moveUpDistance = 80f; // UI座標(px)なので大きめの値
    private float duration = 0.8f;

    void Awake()
    {
        canvasGroup = GetComponent<CanvasGroup>();
        rectTransform = GetComponent<RectTransform>();
        canvasGroup.interactable = false;
        canvasGroup.blocksRaycasts = false;
    }

    //Managerから呼び出され、初期化
    //初期化後にpopup
    public void Setup(Color color, float size, float scale, string damage, float dis, float dur)
    {
        damageText.color = color;
        damageText.fontSize = size;
        damageText.text = damage;
        popScale = scale;

        moveUpDistance = dis;
        duration = dur;

        PlayAnimation();
    }

    private void PlayAnimation()
    {
        rectTransform.localScale = Vector3.zero;
        canvasGroup.alpha = 1f;

        Sequence seq = DOTween.Sequence();

        // 出現時のポップ演出
        seq.Append(rectTransform.DOScale(popScale, 0.15f).SetEase(Ease.OutBack));

        // 上に移動しつつフェードアウト
        seq.Join(rectTransform.DOAnchorPosY(rectTransform.anchoredPosition.y + moveUpDistance, duration).SetEase(Ease.OutCubic));
        seq.Append(canvasGroup.DOFade(0f, 0.25f));

        seq.OnComplete(() => Destroy(gameObject));
    }
}
