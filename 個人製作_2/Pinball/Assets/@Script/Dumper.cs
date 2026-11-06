using UnityEngine;
using DG.Tweening;

public class Dumper : MonoBehaviour
{
    [SerializeField] float power = 4f;

    void OnCollisionEnter(Collision c)
    {
        if (c.rigidbody == null) return;

        Vector3 dir = c.transform.position - c.GetContact(0).point; //接触点からボールの中心へ向かうベクトル
        dir = Vector3.ProjectOnPlane(dir, transform.up).normalized; //ベクトルから台の面に垂直な成分を取り除く  //normalizedでベクトル強度を1に
        c.rigidbody.AddForce(dir * power, ForceMode.Impulse);       //射出

        gameObject.transform.DOPunchScale(Vector3.one * 5f, 0.5f, 10, 1);　//ボヨンってなる
    }
}
