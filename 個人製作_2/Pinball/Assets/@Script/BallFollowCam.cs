using UnityEngine;

public class BallFollowCam : MonoBehaviour
{
    [Header("位置の追従")]
    [Tooltip("0=位置固定で首振りのみ / 1=オフセット維持で完全追従")][SerializeField, Range(0f, 1f)] float positionFollow = 0.5f;
    [SerializeField] float positionSmoothTime = 0.15f;

    [Header("注視")]
    [Tooltip("注視点の追従の滑らかさ")][SerializeField] float lookSmoothTime = 0.1f;

    Camera thisCam;
    Transform target;
    Vector3 offset;
    Vector3 initialPos;
    Vector3 initialUp;
    Vector3 posVelocity;
    Vector3 focusPoint;
    Vector3 focusVelocity;
    bool initialized;

    public bool IsActive => target != null;

    private void Awake()
    {
        thisCam = GetComponent<Camera>();
        if (thisCam == null)
        {
            Debug.LogError("BallFollowCam: Camera component not found.");
            enabled = false;
        }
    }

    void LateUpdate()
    {
        if (target == null)
        {
            target = FindNextTarget();
            thisCam.enabled = true;
            if (target == null) 
            {
                thisCam.enabled = false;
                return;
            }

            if (!initialized)
            {
                offset = transform.position - target.position;
                initialPos = transform.position;
                initialUp = transform.up;
                focusPoint = target.position;
                initialized = true;
            }
        }

        // 位置
        Vector3 followPos = target.position + offset;
        Vector3 desiredPos = Vector3.Lerp(initialPos, followPos, positionFollow);
        transform.position = Vector3.SmoothDamp(
            transform.position, desiredPos, ref posVelocity, positionSmoothTime);

        // 注視点を滑らかに追い、そこへ向ける
        focusPoint = Vector3.SmoothDamp(
            focusPoint, target.position, ref focusVelocity, lookSmoothTime);
        transform.LookAt(focusPoint, initialUp);
    }

    Transform FindNextTarget()
    {
        Transform best = null;
        float bestDist = float.MaxValue;
        foreach (var b in BallRegistry.Balls)
        {
            if (b == null) continue;
            float d = (b.position - transform.position).sqrMagnitude;
            if (d < bestDist) { bestDist = d; best = b; }
        }
        return best;
    }
}