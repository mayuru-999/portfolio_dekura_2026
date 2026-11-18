using UnityEngine;
using DG.Tweening;

public class Dumper : MonoBehaviour
{
    [SerializeField] float power = 4f;
    [SerializeField] Transform visual;
    [SerializeField] Vector3 punch = new Vector3(0.3f, 0.3f, 0.3f);     // 台の面に沿って膨らませる

    Vector3 baseScale;
    Tween punchTween;

    void Awake()
    {
        baseScale = visual.localScale;
    }

    void OnCollisionEnter(Collision c)
    {
        if (c.rigidbody == null) return;

        Vector3 dir = c.transform.position - c.GetContact(0).point;     //接触点からボールの中心へ向かうベクトル
        dir = Vector3.ProjectOnPlane(dir, transform.up).normalized;     //ベクトルから台の面に垂直な成分を取り除く//normalizedでベクトル強度を1
        c.rigidbody.AddForce(dir * power, ForceMode.Impulse);           //射出

        punchTween?.Kill();
        visual.localScale = baseScale;                                // 毎回、元の大きさに戻してから始める
        punchTween = visual.DOPunchScale(punch, 0.5f, 10, 1f)
                           .SetLink(visual.gameObject);
    }
}